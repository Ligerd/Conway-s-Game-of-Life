out: main.c png_input/png_input.c png_input/png_input.h matrix_of_cells/matrix_of_cells.c matrix_of_cells/matrix_of_cells.h read_arguments/read_arguments.c read_arguments/read_arguments.h txt_input/txt_input.c txt_input/txt_input.h rules/rules.c rules/rules.h write_png/write_png.c write_png/write_png.h cellular_automaton/cellular_automaton.c cellular_automaton/cellular_automaton.h
	  @ gcc main.c png_input/png_input.c txt_input/txt_input.c rules/rules.c write_png/write_png.c matrix_of_cells/matrix_of_cells.c read_arguments/read_arguments.c cellular_automaton/cellular_automaton.c   -lpng  -std=c99
clean:
	@rm -f wyniki/*.png 
test:
	@echo Test rules
	+$(MAKE) -C rules
	@echo Test txt_input
	+$(MAKE) -C txt_input
	@echo Test png_input
	+$(MAKE) -C png_input
	@echo Test write_png	
	+$(MAKE) -C write_png
	
