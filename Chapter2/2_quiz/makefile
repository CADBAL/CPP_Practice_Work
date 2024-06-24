2.12: link_main

link_main: main.o io.o
	g++ main.o io.o -o main.exe

compile_main_test: link_main_test
	g++ main.cpp io.cpp -c
	
clean:
	rm *.o *.exe

