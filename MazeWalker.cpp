/**
*       @file : MazeWalker.cpp
*       @author : Ethan Ward
*       @date : 2015.04.17
*       @brief: Implements the methods listed in MazeWalker.cpp
*/
#include "MazeWalker.h"

MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs)
		: m_curPos(startRow, startCol), m_startPos(startRow, startCol) {

	m_rows = rows;
	m_cols = cols;
	m_maze = new char*[m_rows];

	for(int i = 0; i < m_rows; i++) {
		m_maze[i] = new char[m_cols];
	}	

	for(int i = 0; i < m_rows; i++) {
		for(int j = 0; j < m_cols; j++) {
			m_maze[i][j] = mazePtr[i][j];
		}
	}

	m_visited = new bool*[m_rows];
	
	for(int i = 0; i < m_rows; i++) {
		m_visited[i] = new bool[m_cols];
	}

	for(int i = 0; i < m_rows; i++) {
		for(int j = 0; j < m_cols; j++) {
			m_visited[i][j] = false;
		}
	}

	m_isDFS = dfs;


}

void MazeWalker::walkMaze() throw (std::runtime_error){

	move(m_curPos);
	printVisited();	

	if(m_isDFS) {	
		
		while(!compare() ) {
	
			storeValidMoves();
			move(m_moveStack.top());
			m_moveStack.pop();
			printVisited();
			
			if(isGoalReached()) {
				while(!m_moveStack.empty()) {
					m_moveStack.pop();
				}
				change();	
			}
		}	
	}
	
	else {
		while(!compare()) {
			
			storeValidMoves();
			move(m_moveQueue.front());
			m_moveQueue.pop();
			printVisited();
			if(isGoalReached()) {
				while(!m_moveQueue.empty()) {
					m_moveQueue.pop();
				}
				change();
			}		
		}	
	}

	if(isGoalReached()) {
		std::cout << "\nExit found!\n";
	}

	else { 
		std::cout << "\nNo more moves!\n";
	}
	for(int i = 0; i < m_rows; i++) {
		delete[] m_maze[i];
		delete[] m_visited[i];
	}

	delete[] m_maze;
	delete[] m_visited;


}

void MazeWalker::storeValidMoves() {

	int curRow = m_curPos.getRow();
	int curCol = m_curPos.getCol();

	if(m_isDFS) {
		if(curCol - 1 >= 0) {
			if( (m_maze[curRow][curCol-1] != 'W') && (m_visited[curRow][curCol-1] != 1) ) {
				Position left = Position(curRow, curCol - 1);
				m_moveStack.push(left);
			}
		}

		if(curRow + 1 < m_rows) {
			if( (m_maze[curRow+1][curCol] != 'W') && (m_visited[curRow+1][curCol] != 1) ) {
				Position down = Position(curRow + 1, curCol);
				m_moveStack.push(down);
			}
		}

		if(curCol + 1 < m_cols) {
			if( (m_maze[curRow][curCol+1] != 'W') && (m_visited[curRow][curCol+1] != 1) ) {
				Position right = Position(curRow, curCol + 1);
				m_moveStack.push(right); 
			}
		}

		if(curRow - 1 >= 0) {
			if( (m_maze[curRow-1][curCol] != 'W') && (m_visited[curRow-1][curCol] != 1) ) {
				Position up = Position(curRow - 1, curCol);
				m_moveStack.push(up); 
			}
		}
		
		

		

		
	}

	else {
		if(curRow - 1 >= 0) {
			if( (m_maze[curRow-1][curCol] != 'W') && (m_visited[curRow-1][curCol] != 1) ) {				
				Position up = Position(curRow - 1, curCol);
				m_moveQueue.push(up); 
			}
		}
		
		if(curCol + 1 < m_cols) {
			if( (m_maze[curRow][curCol+1] != 'W') && (m_visited[curRow][curCol+1] != 1) ) {
				Position right = Position(curRow, curCol + 1);
				m_moveQueue.push(right);
			}
		}

		if(curRow + 1 < m_rows) {
			if( (m_maze[curRow+1][curCol] != 'W') && (m_visited[curRow+1][curCol] != 1) ) {
				Position down = Position(curRow + 1, curCol);
				m_moveQueue.push(down);
			}
		}

		if(curCol - 1 >= 0) {
			if( (m_maze[curRow][curCol-1] != 'W') && (m_visited[curRow][curCol-1] != 1) ) {
				Position left = Position(curRow, curCol - 1);
				m_moveQueue.push(left);
			}
		}
	}

}

void MazeWalker::move(Position& p) {

	m_curPos = Position(p.getRow(), p.getCol());

	m_visited[m_curPos.getRow()][m_curPos.getCol()] = true;

}

bool MazeWalker::isGoalReached() const {
	
	if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E') {
		return(true);
	}

	else {
		return(false);
	}
}

void MazeWalker::printVisited() const {

	for(int i = 0; i < m_rows; i++) {
		for(int j = 0; j < m_cols; j++) {
			std::cout << m_visited[i][j];
		}
		std::cout << "\n";
	}

	std::cout << "Visiting position: " << m_curPos.getRow() << ", " << m_curPos.getCol()  << "\n";

	std::cout << "-------------------------\n";

}

bool MazeWalker::compare() {

	for(int i = 0; i < m_rows; i++) {
		for(int j = 0; j < m_rows; j++) {
			if(m_maze[i][j] == 'P' || m_maze[i][j] == 'E') {
				if(m_visited[i][j] != 1) {
					return(false);
				} 
			}
		}
	}

	return(true);

}

void MazeWalker::change() {
for(int i = 0; i < m_rows; i++) {
		for(int j = 0; j < m_rows; j++) {
			if(m_maze[i][j] == 'P' || m_maze[i][j] == 'E') {
				m_visited[i][j] = 1;
			}
		}
	}
}
