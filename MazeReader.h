/**
*       @file : MazeReader.h
*       @author : Ethan Ward
*       @date : 2015.04.17
*       @brief: Reads in a correctly formatted maze file and extracts the maze and all relevant information about the maze from it. If the file is not correctly formatted, throws an except$
*/
#ifndef MAZEREADER_H
#define MAZEREADER_H

#include "MazeCreationException.h"
#include <fstream>
#include <string>
#include <iostream>

class MazeReader {
	public:
/**
	*  @pre None
	*  @post Creates a MazeReader and allocates a 2D char array with the maze information.
	*  @return None
	*  @throws A MazeCreationException if any of the following happen: The file could not be opened, The rows or cols are zero or less, or the start position listed is outside the rang$
	*/
	MazeReader(std::string file) throw (MazeCreationException);

/**
	*  @pre None
	*  @post Deallocates the maze.
	*  @return None
	*/
	~MazeReader();
/**
	*  @pre The file was correctly formatted and read in.
	*  @post None
	*  @return A pointer to the maze.
	*/
	char** getMaze() const;

/**
	*  @pre The file was correctly formatted and read in.
	*  @post None
	*  @return The number of columns in the file.
	*/
	int getCols() const;
/**
	*  @pre The file was correctly formatted and read in.
	*  @post None
	*  @return The number of rows in the file.
	*/
	int getRows() const;
/**
	*  @pre The file was correctly formatted and read in.
	*  @post None
	*  @return The starting column.
	*/
	int getStartCol() const;
/**
	*  @pre The file was correctly formatted and read in.
	*  @post None
	*  @return The starting row.
	*/
	int getStartRow() const;

	protected:
/**
	*  @pre The file was correctly formatted.
	*  @post Stores the characters representing the maze.
	*  @return None
	*/
	void readMaze() throw (MazeCreationException);
	std::ifstream iFile;
	int m_cols, m_rows, m_startCol, m_startRow;
	char** maze;
};

#endif
