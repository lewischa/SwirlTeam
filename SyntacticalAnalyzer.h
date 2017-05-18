/********************************************************************************/
/* Project: 									*/
/* Author: 									*/
/* Date: 									*/
/* Description:									*/
/********************************************************************************/

#ifndef SYN_H
#define SYN_H

#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.h"
#include "CodeGenerator.h"

using namespace std;

class SyntacticalAnalyzer 
{
    public:
	SyntacticalAnalyzer (char * filename);
	~SyntacticalAnalyzer ();
    private:
	LexicalAnalyzer * lex;
	CodeGenerator * codegen;
	ofstream p2file;
	token_type token;
	int program ();
	//int errors;
	int define ();
	int more_defines ();
	int param_list ();
	int stmt ( bool shouldReturn = false );
	int literal ();
	int action (bool shouldReturn = false );
	int stmt_list ( bool shouldReturn = false, string separator = "" );
	int quoted_lit ();
	int any_other_token ();
	int more_tokens ();
	int else_part ();
};
	
#endif
