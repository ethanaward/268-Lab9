/**
*       @file : MazeWalker.h
*       @author : Ethan Ward
*       @date : 2015.04.17
*       @brief: Takes in a maze with its parameters and traverses it until either it finds the end or it is out of moves. Contains helper methods for traversing the maze.
*/
#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include "Position.h"
#include <stack>
#include <queue>
#include <iostream>
#include <stdexcept>

class MazeWalker {

public:
/**
	*  @pre The mazePtr pointer is to a valid maze.
	*  @post A maze walker is created with all needed flags set and with the visted array containing all false.
	*  @return None
	*/
	MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);
/**
	*  @pre The maze is a valid maze.
	*  @post The maze is traversed using DFS or BFS until either the end is reached or all moves are exhausted. The visited array is printed during the traversal.
	*  @return None
	*/
	void walkMaze() throw (std::runtime_error);
protected:
/**
	*  @pre The current position is valid.
	*  @post Either the stack or queue is loaded with valid moves from the valid position.
	*  @return None.
	*/
	void storeValidMoves();
/**
	*  @pre The position is valid.
	*  @post The current position is set to p and the previous position is set to visited.
	*  @return None
	*/
	void move(Position& p);
/**
	*  @pre None
	*  @post None
	*  @return True if the current position is the exit, false otherwise.
	*/
	bool isGoalReached() const;
/**
	*  @pre None
	*  @post Prints out the visited array, along with the current position.
	*  @return None
	*/
	void printVisited() const;
/**
	*  @pre None
	*  @post None
	*  @return True if all of the possible positions have been visited, false otherwise.
	*/
	bool compare();
/**
	*  @pre None
	*  @post Sets all of the possible positions to visited to end the loop.
	*  @return None
	*/
	void change();



	bool m_isDFS;
	char** m_maze;
	bool** m_visited;
	int m_rows, m_cols;
	bool canMove;
	Position m_curPos;
	Position m_startPos;
	std::stack<Position> m_moveStack;
	std::queue<Position> m_moveQueue;
};

#endif

