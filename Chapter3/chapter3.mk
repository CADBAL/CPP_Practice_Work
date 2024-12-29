Test: link_chapter_3

link_chapter_3: chapter_3_assign_1.o
	g++ chapter_3_assign_1.o -o main.exe

compile_chapter_3: link_chapter_3
	g++ chapter_3_assign_1.cpp

clean:
	rm *.o *.exe
