/**
*       @file : Position.h
*       @author : Ethan Ward
*       @date : 2015.04.17
*       @brief: Creates Positions, which are basic objects with a row and a column. Also contains methods for getting those two values.
*/
#ifndef POSITION_H
#define POSITION_H

class Position {

public:
	Position(int row, int col);
	int getRow() const;
	int getCol() const;
private:
	int m_row;
	int m_col;
};

#endif
