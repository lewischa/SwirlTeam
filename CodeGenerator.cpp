#include <stdio.h>
#include <string.h>
#include "CodeGenerator.h"

using namespace std;

CodeGenerator::CodeGenerator( char * file ) {
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
	cppFile.close();
}

void CodeGenerator::writeIncludes() {
	// write some #include stuff to cppFile here
	cppFile << "#include <iostream>\n";
	cppFile << "#include \"Object.h\"\n\n";
	cppFile << "using namespace std;\n\n";
}


void CodeGenerator::defineMain()
{
	isMain = true;
	cppFile << "int main(";
}


void CodeGenerator::defineFunction( string ident )
{
	isMain = false;
	cppFile << "Object " << ident << "(";
}


void CodeGenerator::endFunction()
{
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
	indentCode();
	cppFile << "__retVal = Object(" << toReturn << ");\n";
}


void CodeGenerator::returnCreatedObject( string toReturn )
{
	cppFile << "return __retVal;\n";
}


void CodeGenerator::writeCode( string code )
{
	cppFile << code;
}


void CodeGenerator::if_beginCondition()
{
	indentCode();
	cppFile << "if (";
}



void CodeGenerator::if_endCondition()
{
	cppFile << ")\n";
    indentCode();
    cppFile << "{\n";
    addIndent();
}


void CodeGenerator::else_begin()
{
	indentCode();
  	cppFile << "else\n";
  	indentCode();
  	cppFile << "{\n";
  	addIndent();
  	indentCode();
}



void CodeGenerator::endControlStructure()
{
	minusIndent();
	indentCode();
	cppFile << "}\n";
}


void CodeGenerator::newline()
{
	indentCode();
	cppFile << "cout << endl;\n";
}


void CodeGenerator::callFunction( string functionName )
{
	// indentCode();
	cppFile << functionName << "(";
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




