//	Authors:		Ivan Lim, Brooke Borges, Chad Lewis
//	Class:			CS 460, Programming Languages
//	Assignment:		Project 3
//	File:			CodeGenerator.h
//	Date:			Spring 2017


#ifndef CG_H
#define CG_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Object.h"

class CodeGenerator {
public:
	CodeGenerator( char * );
	~CodeGenerator();

	void defineMain();
	void defineFunction( string );
	void endFunction();
	void returnIdentifier( string );
	void returnCreatedObject( string );
	void writeCode( string );
	void callFunction( string );
	void callListOp( string );
	void addParameter( string );
	void endParameters();
	void makeObject_begin();
	void makeObject_end();
	void addToListStack( string );
	void endList();
	void if_beginCondition();
	void if_endCondition();
	void else_begin();
	void endControlStructure();
	void newline();
	void addIndent();
	void minusIndent();
	void indentCode();
	void displayOutput();

private:
	ofstream cppFile;
	vector<string> params;
	vector<string> listStack;
	bool isMain;
	int numTabsIndented;
	void writeIncludes();
};

#endif
