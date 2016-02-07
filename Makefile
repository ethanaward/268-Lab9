Lab9: main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o
	g++ -g -std=c++11 -Wall -o Lab9 main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -std=c++11 -Wall -c MazeReader.h MazeReader.cpp

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -Wall -c MazeCreationException.h MazeCreationException.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -std=c++11 -Wall -c MazeWalker.h MazeWalker.cpp

Position.o: Position.h Position.cpp
	g++ -g -std=c++11 -Wall -c Position.h Position.cpp

clean:
	rm *.o Lab9
	echo clean done
