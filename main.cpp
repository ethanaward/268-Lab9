/**
*       @file : main.cpp
*       @author : Ethan Ward
*       @date : 2015.04.17
*       @brief: Takes in and validates the command line arguments. After they a$
*/
#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include "MazeReader.h"
#include "MazeWalker.h"
#include <string>

int main(int argc, char** argv) {

bool dfs = true;

if(argc !=3) {
	std::cout << "Bad number of arguments. 3 must be given.";
}	

else if((std::string)argv[2] != "-dfs" && (std::string)argv[2] != "-bfs") {
	std::cout << "The search option must be -dfs or -bfs";
}

else {

	try {	
		if((std::string)argv[2] == "-bfs") {
			dfs = false;
		}
		MazeReader* mazeR = new MazeReader((std::string)argv[1]);
		MazeWalker* mazeW = new MazeWalker(mazeR->getMaze(), mazeR->getStartRow(), mazeR->getStartCol(), mazeR->getRows(), mazeR->getCols(), dfs);

		mazeW->walkMaze(); 

		delete mazeR;
		delete mazeW;
	}
	catch(std::runtime_error e) {
		std::cout << e.what();
	}

}

};

#endif

