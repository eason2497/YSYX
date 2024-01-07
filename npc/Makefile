all:
	@echo "Write this Makefile by your self."

sim:	*.cpp *.v
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator --cc --exe --build -j 0 -Wall *.cpp *.v

include ../Makefile
