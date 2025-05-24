Test: link_chapter_3,6

link_chapter_3: chapter_3.6.o
	g++ chapter_3.6.o -o main.exe

compile_chapter_3: link_chapter_3.6
	g++ chapter_3,6.cpp

clean:
	rm *.o *.exe
 