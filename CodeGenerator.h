#ifndef CG_H
#define CG_H

#include <iostream>
#include <fstream>
#include "Object.h"

class CodeGenerator {
public:
	CodeGenerator( char * );
	~CodeGenerator();

	void startProgram();

private:
	ofstream cppFile;
};

#endif