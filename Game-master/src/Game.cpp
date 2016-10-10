#include <thread>
#include "Game.h"
#include "Entity.h"
#include "Unit.h"
#include "GameObject.h"
#include "Player.h"
#include "Map.h"
#include "Menu.h"
#include "ResourceManager.h"

#include <Thor/Input.hpp>

Game* Game::_instance = nullptr;

Game::Game() : window(sf::VideoMode(1000, 600), "Game"), CurrentMap(nullptr), MenuMap(nullptr), fps(0), 
debugMode(false), State(GAME_STATE_NONE), PreviousState(GAME_STATE_NONE),
InputHandler(this)
{
    window.setFramerateLimit(120);
    window.setKeyRepeatEnabled(false);
}

Game::~Game()
{
    delete CurrentMap;
    delete MenuMap;

    for (std::list<Player*>::iterator itr = Players.begin(); itr != Players.end(); ++itr)
        delete *itr;
    Players.clear();

    for (std::list<Entity*>::iterator itr = Entities.begin(); itr != Entities.end(); ++itr)
        delete *itr;
    Entities.clear();

    if (window.isOpen())
        window.close();
}

void Game::Start()
{
    sf::Clock timer;
    sf::Clock fpsTimer;
    int frames = 0;

    while (window.isOpen())
    {
        ++frames;
        if (fpsTimer.getElapsedTime().asSeconds() >= 1)
        {
            fps = frames;
            frames = 0;
            fpsTimer.restart();
        }

        if (State == GAME_STATE_NONE)
            State = GAME_STATE_MENU;

        sf::Time diff = timer.restart();
        if (State == GAME_STATE_PAUSED)
            diff = sf::Time(); // Do not count ticks if the game is paused
        Update(diff);
    }
}

void Game::Update(sf::Time const diff)
{
    // Handle the events
    /*sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::LostFocus:
                PreviousState = State;
                State = GAME_STATE_PAUSED;
                break;
            case sf::Event::GainedFocus:
                State = PreviousState;
                PreviousState = GAME_STATE_NONE;
                return; // Process on next tick
            case sf::Event::Resized:
                window.setView(sf::View(sf::FloatRect(0.f, 0.f, float(event.size.width), float(event.size.height))));
                break;
            case sf::Event::KeyPressed:
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Q:
                        GetPlayer()->EmitParticle(sf::seconds(1), true);
                        break;
                    case sf::Keyboard::Up:
                        if (State == GAME_STATE_MENU)
                            MenuMap->ChangeOption(true);
                        break;
                    case sf::Keyboard::Down:
                        if (State == GAME_STATE_MENU)
                            MenuMap->ChangeOption(false);
                        break;
                    case sf::Keyboard::BackSpace:
                        if (State == GAME_STATE_MENU)
                            MenuMap->ChangeMenu(true);
                        break;
                    case sf::Keyboard::Space:
                        if (State == GAME_STATE_MENU)
                            MenuMap->ChangeMenu(false);
                        else if (State == GAME_STATE_PLAYING)
                            GetPlayer()->Jump();
                        break;
                    case sf::Keyboard::R:
                        PrepareWorld();
                        break;
                }
                break;
            }
        }
    }*/

    InputHandler.Update(window);

    if (InputHandler.IsActive(0, ACTION_ENABLE_DEBUG))
        debugMode ^= true;

    if (InputHandler.IsActive(0, ACTION_ENTER))
        if (State == GAME_STATE_MENU)
            MenuMap->ChangeMenu(false);

    if (State == GAME_STATE_PAUSED)
        return;

    window.clear(sf::Color(136, 247, 255));

    if (State == GAME_STATE_PLAYING)
    {
        if (CurrentMap)
            CurrentMap->Update(diff);

        for (std::list<Entity*>::iterator itr = Entities.begin(); itr != Entities.end(); ++itr)
            (*itr)->Update(diff);

        for (std::list<Player*>::iterator itr = Players.begin(); itr != Players.end(); ++itr)
            (*itr)->Update(diff);
    }
    else if (State == GAME_STATE_MENU)
    {
        if (!MenuMap)
            MenuMap = new Menu(this);
        MenuMap->Update(diff);
    }

    DrawTexts();
    window.display();

    if (State == GAME_STATE_PLAYING)
    {
        sf::View view = window.getView();
        view.setCenter(GetPlayer()->GetPositionX(), GetPlayer()->GetPositionY());
        window.setView(view);
    }
}

void Game::DrawTexts()
{
    sf::Font& font = sResourceManager->GetFont("arial.ttf");

    sf::Vector2f topLeft;
    topLeft.x = window.getView().getCenter().x - window.getSize().x / 2.f;
    topLeft.y = window.getView().getCenter().y - window.getSize().y / 2.f;

    if (State == GAME_STATE_LOADING_LEVEL)
    {
        sf::Text text("Loading Level", font);
        text.setColor(sf::Color::White);
        text.setPosition(window.getView().getCenter().x - 90.f, window.getView().getCenter().y - 35.f);
        text.setStyle(sf::Text::Style::Bold);
        window.draw(text);
    }

    // Draw debug information
    if (debugMode)
    {
        // Draw the FPS text on the screen
        sf::Text fpsText(std::to_string(fps) + " FPS", font);
        fpsText.setColor(sf::Color::Red);
        fpsText.setStyle(sf::Text::Style::Bold);
        fpsText.setPosition(topLeft);
        fpsText.setCharacterSize(12);
        window.draw(fpsText);

        if (State == GAME_STATE_PLAYING)
        {
            Player* plr = GetPlayer(0);
            sf::Text posText("X: " + std::to_string(plr->Position.x) + " Y: " + std::to_string(plr->Position.y), font);
            posText.setColor(sf::Color::Red);
            posText.setStyle(sf::Text::Style::Bold);
            posText.setPosition(topLeft.x, topLeft.y + window.getSize().y - 17.f);
            posText.setCharacterSize(12);
            window.draw(posText);
        }
    }
}

void Game::PrepareWorld()
{
    // Don't try to launch another thread if there's already a level being loaded
    if (State == GAME_STATE_LOADING_LEVEL)
        return;

    State = GAME_STATE_LOADING_LEVEL;
    
    // Create a thread to load the level
    std::thread loader([&]() {
        for (auto itr = Players.begin(); itr != Players.end(); ++itr)
            delete *itr;
        Players.clear();

        for (auto itr = Entities.begin(); itr != Entities.end(); ++itr)
            delete *itr;
        Entities.clear();

        delete CurrentMap;
        CurrentMap = new Map(this);
        CurrentMap->Load();

        for (unsigned int i = 0; i < Common::NumPlayers; ++i)
        {
            Player* player = new Player(this, i, "p1/p1_walk08.png");
            CurrentMap->AddPlayer(player);
            Players.push_back(player);
        }

        State = GAME_STATE_PLAYING;
    });

    // Start the loader
    loader.detach();
}

Player* Game::GetPlayer(int index /*= 0*/)
{
    if (Players.empty())
        return nullptr;

    auto itr = Players.begin();
    std::advance(itr, index);
    
    if (itr == Players.end())
        return nullptr;

    return *itr;
}
