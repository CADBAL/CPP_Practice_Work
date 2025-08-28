Q2: link_Q2

link_Q2: q2.o arithmetic_input.o arithmetic_operation.o double_input.o
	g++ q2.o arithmetic_input.o arithmetic_operation.o double_input.o -o q2.exe

compile_Q2: link_Q2
	g++ q2.cpp arithmetic_input.cpp arithmetic_operation.cpp double_input.cpp -c

clean:
	rm *.o *.exe

