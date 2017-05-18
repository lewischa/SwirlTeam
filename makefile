P3.out : Project3.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o Object.o CodeGenerator.o
	g++ -std=c++11 -g -o P3.out Project3.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o Object.o CodeGenerator.o

Project3.o : Project3.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -std=c++11 -g -c Project3.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -std=c++11 -g -c SetLimits.cpp

LexicalAnalyzer.o : LexicalAnalyzer.save
	cp LexicalAnalyzer.save LexicalAnalyzer.o

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h LexicalAnalyzer.h Object.h CodeGenerator.h
	g++ -std=c++11 -g -c SyntacticalAnalyzer.cpp

Object.o: Object.cpp Object.h
	g++ -std=c++11 -g -c Object.cpp

CodeGenerator.o: CodeGenerator.cpp CodeGenerator.h Object.h
	g++ -std=c++11 -g -c CodeGenerator.cpp

clean : 
	rm -rf *.o *.out *.gch
