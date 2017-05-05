//	Authors:		Ivan Lim, Brooke Borges, Chad Lewis
//	Class:			CS 460, Programming Languages
//	Assignment:		Project 3
//	File:			Project3.cpp
//	Date:			Spring 2017


#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "SetLimits.h"
#include "SyntacticalAnalyzer.h"

int main( int argc, char * argv[] ) {
	if ( argc < 2 ) {
		printf("Format: executable <filename>\n");
		exit(1);
	}

	SetLimits();
	SyntacticalAnalyzer parse ( argv[1] );

	return 0;
}