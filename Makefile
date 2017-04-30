.PHONY: clean All

All:
	@echo "----------Building project:[ week1-opdracht1 - Debug ]----------"
	@cd "week1-opdracht1" && "$(MAKE)" -f  "week1-opdracht1.mk"
clean:
	@echo "----------Cleaning project:[ week1-opdracht1 - Debug ]----------"
	@cd "week1-opdracht1" && "$(MAKE)" -f  "week1-opdracht1.mk" clean
