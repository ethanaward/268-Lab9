/**
*       @file : MazeCreationException.h
*       @author : Ethan Ward
*       @date : 2015.04.17
*       @brief: Inherits from std::runtime_error to create a new type of exception that passes in a message to the std::runtime_error constructor.
*/
#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H

#include <stdexcept>

class MazeCreationException: public std::runtime_error{

public:
/**
        *  @pre None
        *  @post Creates a MazeCreationException, and passes the message taken in to the std::runtime_error constructor
        *  @return None
        */
        MazeCreationException(const char* message);
};

#endif

