/**
*       @file : MazeCreationException.cpp
*       @author : Ethan Ward
*       @date : 2015.04.10
*       @brief: Implements the functionality of MazeCreationException.h.
*/
#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message):std::runtime_error(message) {

}
