project1.exe : SetMap.o Time.o main.o
	g++ -o project1.exe SetMap.o Time.o main.o -lncurses

main.o : main.cpp SetMap.h Time.h
	g++ -c main.cpp -lncurses

SetMap.o : SetMap.o SetMap.h
	g++ -c SetMap.cpp

Time.o : Time.o Time.h
	g++ -c Time.cpp

