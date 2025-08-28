Q3: link_Q3

link_Q3: q3.o read_initial_height.o read_current_height.o height_of_ball_for_5_seconds.o 
	g++ q3.o read_initial_height.o read_current_height.o height_of_ball_for_5_seconds.o -o q3.exe

compile_Q3: link_Q3
	g++ q3.cpp read_initial_height.cpp read_current_height.cpp height_of_ball_for_5_seconds.cpp -c

clean:
	rm *.o* *.exe*

