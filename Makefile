.PHONY: clean All

All:
	@echo "----------Building project:[ RiverRaid - Debug ]----------"
	@cd "RiverRaid" && "$(MAKE)" -f  "RiverRaid.mk"
clean:
	@echo "----------Cleaning project:[ RiverRaid - Debug ]----------"
	@cd "RiverRaid" && "$(MAKE)" -f  "RiverRaid.mk" clean
