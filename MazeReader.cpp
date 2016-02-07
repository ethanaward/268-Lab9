/**
*       @file : MazeReader.cpp
*       @author : Ethan Ward
*       @date : 2015.04.17
*       @brief: Implements the methods listed in MazeReader.h
*/
#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException) {

	iFile.open(file);

	if(!iFile.good()) {
		throw MazeCreationException("File is not accessible");
	}

	else {
		readMaze();
	}
}

MazeReader::~MazeReader() {

	for(int i = 0; i < m_rows; i++) {
		delete[] maze[i];
	}

	delete[] maze;
}

char** MazeReader::getMaze() const {

	return(maze);

}

int MazeReader::getCols() const {

	return(m_cols);

}

int MazeReader::getRows() const {

	return(m_rows);

}

int MazeReader::getStartCol() const {

	return(m_startCol);

}

int MazeReader::getStartRow() const {

	return(m_startRow);

}

void MazeReader::readMaze() throw(MazeCreationException) {


	iFile >> m_rows;
	if(m_rows < 1) {
		throw MazeCreationException("The number of rows is less than one");
	}
	
	else {
		maze = new char*[m_rows];
	
		iFile >> m_cols;

		if(m_cols < 1) {
			throw MazeCreationException("The number of columns is less than one");
		}

		else {
			for(int i = 0; i < m_rows; i++) {
				maze[i] = new char[m_cols];
			}

			iFile >> m_startRow;
			iFile >> m_startCol;
				
			if(m_startRow < 0 || m_startCol < 0 || m_startRow > m_rows || m_startCol > m_cols) {
				throw MazeCreationException("The starting position given is outside the specified range");
			}
	
			else {
				for(int i = 0; i < m_rows; i++) {
					for(int j = 0; j < m_cols; j++) {
						iFile >> maze[i][j];
					}
				}
			}				
			
		}
	}	
}
