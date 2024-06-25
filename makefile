Test: link_main_test

link_main_test: main_test.o optional_test.o
	g++ main_test.o optional_test.o -o main.exe

compile_main_test: link_main_test
	g++ main_test.cpp optional_test.cpp -c

clean:
	rm *.o *.exe





