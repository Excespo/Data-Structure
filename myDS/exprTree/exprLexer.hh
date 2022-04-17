#ifndef _EXPRLEXER__H
#define _EXPRLEXER__H

//#include "binaryNodeADT.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using strVec = std::vector<std::string>;
using exprVec = std::vector<std::string>;
using exprsVec = std::vector<exprVec>;
template <typename T> using vec2d = std::vector<std::vector<T>>;

/* 
 * Name - readFile
 * Input - String as file name
 * Output - File content
 */
strVec readFile(std::string);

/* 
 * Name - lexit
 * Input - stdin stream
 * Output - Content after lexing the instream
 */
exprVec lexer(std::string &);

#endif