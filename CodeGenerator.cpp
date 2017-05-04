#include <stdio.h>
#include <string.h>
#include "CodeGenerator.h"

using namespace std;

CodeGenerator::CodeGenerator( char * file ) {
	int fileNameLength = strlen( file );
	char filename[fileNameLength + 1];
	strcpy( filename, file );
	filename[fileNameLength - 2] = 'c';
	filename[fileNameLength - 1] = 'p';
	filename[fileNameLength] = 'p';
	cppFile.open( filename );
}


CodeGenerator::~CodeGenerator() {
	cppFile.close();
}

void CodeGenerator::startProgram() {
	// write some #include stuff to cppFile here
}