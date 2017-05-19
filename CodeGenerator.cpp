//	Authors:		Ivan Lim, Brooke Borges, Chad Lewis
//	Class:			CS 460, Programming Languages
//	Assignment:		Project 3
//	File:			CodeGenerator.cpp
//	Date:			Spring 2017


#include <stdio.h>
#include <string.h>
#include "CodeGenerator.h"

using namespace std;

CodeGenerator::CodeGenerator( char * file ) {
/********************************************************************************/
/* This function initializes the CodeGenerator object.		                    */
/********************************************************************************/
	isMain = false;
	int fileNameLength = strlen( file );
	// cout << "file name: " << file << endl;
	// cout << "length: " << fileNameLength << endl;
	char filename[fileNameLength + 1];
	strncpy( filename, file, fileNameLength );
	filename[fileNameLength - 2] = 'c';
	filename[fileNameLength - 1] = 'p';
	filename[fileNameLength] = 'p';
	filename[fileNameLength + 1] = '\0';
	cppFile.open( filename );
	writeIncludes();
}


CodeGenerator::~CodeGenerator() {
/********************************************************************************/
/* This function closes the .cpp file and deletes the object.                   */
/********************************************************************************/
	cppFile.close();
}

void CodeGenerator::writeIncludes() {
/********************************************************************************/
/* This function writes the necessary pre-compiler directives to the beginning  */
/* of the cpp file.											                    */
/********************************************************************************/
	cppFile << "#include <iostream>\n";
	cppFile << "#include \"Object.h\"\n\n";
	cppFile << "using namespace std;\n\n";
}


void CodeGenerator::defineMain()
{
/********************************************************************************/
/* This function writes the function signature for main.	                    */
/********************************************************************************/
	isMain = true;
	cppFile << "int main(";
}


void CodeGenerator::defineFunction( string ident )
{
/********************************************************************************/
/* This function sets up the function signature for any function that is not    */
/* main.													                    */
/********************************************************************************/
	isMain = false;
	cppFile << "Object " << ident << "(";
}


void CodeGenerator::endFunction()
{
/********************************************************************************/
/* This function writes the necessary code to end main or any other function.   */
/********************************************************************************/
	if (isMain)
	{
		indentCode();
		cppFile << "return 0;\n";
		minusIndent();
	} else
	{
		indentCode();
		cppFile << "return __retVal;\n";
		minusIndent();
	}
	cppFile << "}\n\n";
}


void CodeGenerator::returnIdentifier( string toReturn )
{
/********************************************************************************/
/* This function sets toReturn to the value that will ultimately be returned    */
/* from the function.									                        */
/********************************************************************************/
	indentCode();
	cppFile << "__retVal = Object(" << toReturn << ");\n";
}


void CodeGenerator::returnCreatedObject( string toReturn )
{
/********************************************************************************/
/* This function writes the final return statement of non-main functions.       */
/********************************************************************************/
	cppFile << "return __retVal;\n";
}


void CodeGenerator::writeCode( string code )
{
/********************************************************************************/
/* This function writes arbitrary code to the .cpp file.	                    */
/********************************************************************************/
	cppFile << code;
}


void CodeGenerator::if_beginCondition()
{
/********************************************************************************/
/* This function sets up an if statement.					                    */
/********************************************************************************/
	indentCode();
	cppFile << "if (";
}



void CodeGenerator::if_endCondition()
{
/********************************************************************************/
/* This function ends the condition portion of an if statement, and opens the   */
/* control block with an open curly brace '{'.				                    */
/********************************************************************************/
	cppFile << ")\n";
    indentCode();
    cppFile << "{\n";
    addIndent();
}


void CodeGenerator::else_begin()
{
/********************************************************************************/
/* This function sets up an else statement.					                    */
/********************************************************************************/
	indentCode();
  	cppFile << "else\n";
  	indentCode();
  	cppFile << "{\n";
  	addIndent();
  	indentCode();
}



void CodeGenerator::endControlStructure()
{
/********************************************************************************/
/* This function closes a control block such as if or else.                     */
/********************************************************************************/
	minusIndent();
	indentCode();
	cppFile << "}\n";
}


void CodeGenerator::newline()
{
/********************************************************************************/
/* This function writes newline code to the .cpp file.		                    */
/********************************************************************************/
	indentCode();
	cppFile << "cout << endl;\n";
}


void CodeGenerator::callFunction( string functionName )
{
	// indentCode();
	cppFile << functionName << "(";
}


void CodeGenerator::callListOp( string listop )
{
	cppFile << "listop( \"" << listop << "\", ";
}


void CodeGenerator::addParameter( string parameter )
{
	params.push_back( parameter );
}



void CodeGenerator::endParameters()
{
	for ( int i = 0; i < params.size(); i++ )
	{
		cppFile << "Object ";
		if ( i == params.size() - 1 )
		{
			cppFile << params.at(i);
		}
		else
		{
			cppFile << params.at(i) << ", ";
		}
	}
	params.clear();

	cppFile << ")\n";
	cppFile << "{\n";
	if (isMain != 1)	
	{
		addIndent();
		indentCode();
		minusIndent();
		cppFile << "Object __retVal;\n";
	}
} 


void CodeGenerator::makeObject_begin()
{
	cppFile << "Object(";
}



void CodeGenerator::makeObject_end()
{
	cppFile << ")";
}



void CodeGenerator::addToListStack( string listItem )
{
	listStack.push_back( listItem );
}


void CodeGenerator::endList()
{
	cppFile << "(";
	for ( int i = 0; i < listStack.size(); i++ )
	{
		cppFile << listStack.at(i);
		if ( i != listStack.size() - 1 )
		{
			cppFile << " ";
		}
	}
	cppFile << ")";
	listStack.clear();
	makeObject_end();
}



void CodeGenerator::addIndent()
{
	numTabsIndented++;
}



void CodeGenerator::minusIndent()
{
	if (numTabsIndented > 0)
	{
		numTabsIndented--;
	}
}



void CodeGenerator::indentCode()
{
	for ( int i = 0; i < numTabsIndented; i++ )
	{
		cppFile << "    ";
	}
}


void CodeGenerator::displayOutput()
{
	cppFile << "cout << ";
}




