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

private:
	ofstream cppFile;
	vector<string> params;
	vector<string> listStack;
	bool isMain;
	int numTabsIndented;
	void writeIncludes();
};

#endif