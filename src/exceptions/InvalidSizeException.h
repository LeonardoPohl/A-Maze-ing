#include <iostream>

class InvalidSizeException : public std::exception {
char * what () {
        return "The parameter(s) given to initialise the Size are invalid!";
    }
};