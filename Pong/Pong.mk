##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Pong
ConfigurationName      :=Debug
WorkspacePath          := "/home/hanook/Documents/SFML"
ProjectPath            := "/home/hanook/Documents/SFML/Pong"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=hanook
Date                   :=02/03/16
CodeLitePath           :="/home/hanook/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Pong.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/home/hanook/Downloads/SFML-2.3.2/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/home/hanook/Downloads/SFML-2.3.2/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Paddle.cpp$(ObjectSuffix) $(IntermediateDirectory)/Variables.cpp$(ObjectSuffix) $(IntermediateDirectory)/Ball.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hanook/Documents/SFML/Pong/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Paddle.cpp$(ObjectSuffix): Paddle.cpp $(IntermediateDirectory)/Paddle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hanook/Documents/SFML/Pong/Paddle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Paddle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Paddle.cpp$(DependSuffix): Paddle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Paddle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Paddle.cpp$(DependSuffix) -MM "Paddle.cpp"

$(IntermediateDirectory)/Paddle.cpp$(PreprocessSuffix): Paddle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Paddle.cpp$(PreprocessSuffix) "Paddle.cpp"

$(IntermediateDirectory)/Variables.cpp$(ObjectSuffix): Variables.cpp $(IntermediateDirectory)/Variables.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hanook/Documents/SFML/Pong/Variables.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Variables.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Variables.cpp$(DependSuffix): Variables.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Variables.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Variables.cpp$(DependSuffix) -MM "Variables.cpp"

$(IntermediateDirectory)/Variables.cpp$(PreprocessSuffix): Variables.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Variables.cpp$(PreprocessSuffix) "Variables.cpp"

$(IntermediateDirectory)/Ball.cpp$(ObjectSuffix): Ball.cpp $(IntermediateDirectory)/Ball.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hanook/Documents/SFML/Pong/Ball.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Ball.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Ball.cpp$(DependSuffix): Ball.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Ball.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Ball.cpp$(DependSuffix) -MM "Ball.cpp"

$(IntermediateDirectory)/Ball.cpp$(PreprocessSuffix): Ball.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Ball.cpp$(PreprocessSuffix) "Ball.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


