chapter2.9: link_chapter_2.9

link_chapter_2.9: 2.9.o
	g++ 2.9.o -o main.exe

compile_chapter_2.9: link_chapter_2.9
	g++ 2.9.cpp

clean:
	rm *.o *.exe
 
