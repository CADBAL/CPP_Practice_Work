2.8: link_add_2.8 link_input_2.8

link_input_2.8: input.o input_main.o
	g++ input.o input_main.o -o input

compile_input_2.8: link_input_2.8
	g++ input.cpp input_main.cpp -c

link_add_2.8: add.o add_main.o
	g++ add.o add_main.o -o add

compile_add_2.8: link_add_2.8
	g++ add.cpp add_main.cpp -c


clean:
	rm add.o add_main.o input.o input_main.o





