CXX=g++

all:decoder

decoder:
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.1/include -O0 -g3 -Wall -c decoder_2by4.cc
	$(CXX) -L/usr/local/systemc-2.3.1/lib-linux64 -o "decoder" decoder_2by4.o -lsystemc
	
	./decoder
	gtkwave  timing_diagram.vcd

.PHONY:decoder
