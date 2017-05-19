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
/********************************************************************************/
/* This function calls a function with the name passed to it.                   */
/********************************************************************************/
	cppFile << functionName << "(";
}


void CodeGenerator::callListOp( string listop )
{
/********************************************************************************/
/* This function calls the listop function with the listop as a string passed   */
/* to it.													                    */
/********************************************************************************/
	cppFile << "listop( \"" << listop << "\", ";
}


void CodeGenerator::addParameter( string parameter )
{
/********************************************************************************/
/* This function adds a parameter to the list of function parameters in params. */
/********************************************************************************/
	params.push_back( parameter );
}



void CodeGenerator::endParameters()
{
/********************************************************************************/
/* This function marks the end of a param_list. Params are output to the .cpp   */
/* file and the function signature is completed.			                    */
/********************************************************************************/
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
/********************************************************************************/
/* This function writes the code necessary to create an object.                 */
/********************************************************************************/
	cppFile << "Object(";
}



void CodeGenerator::makeObject_end()
{
/********************************************************************************/
/* This function marks the end of a created object, and closes the parentheses. */
/********************************************************************************/
	cppFile << ")";
}



void CodeGenerator::addToListStack( string listItem )
{
/********************************************************************************/
/* This function adds items to a list stack.				                    */
/********************************************************************************/
	listStack.push_back( listItem );
}


void CodeGenerator::endList()
{
/********************************************************************************/
/* This function marks the end of a list, and it writes the entire list to the  */
/* .cpp file.												                    */
/********************************************************************************/
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
/********************************************************************************/
/* This function increments the amount of indents used on new lines.            */
/********************************************************************************/
	numTabsIndented++;
}



void CodeGenerator::minusIndent()
{
/********************************************************************************/
/* This function decrements the amount of indents used on new lines.            */
/********************************************************************************/
	if (numTabsIndented > 0)
	{
		numTabsIndented--;
	}
}



void CodeGenerator::indentCode()
{
/********************************************************************************/
/* This function writes the necessary number of spaces for indentation.         */
/********************************************************************************/
	for ( int i = 0; i < numTabsIndented; i++ )
	{
		cppFile << "    ";
	}
}


void CodeGenerator::displayOutput()
{
/********************************************************************************/
/* This function writes the initial code for (display 'some_thing)              */
/********************************************************************************/
	cppFile << "cout << ";
}




