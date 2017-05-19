#include <iostream>
#include "Object.h"

using namespace std;

Object funky(Object a)
{
    Object __retVal;
    cout << Object("this_is_an_IDENT_T");
    cout << endl;
    cout << Object("532");
    cout << endl;
    cout << Object("cons");
    cout << endl;
    cout << Object("if");
    cout << endl;
    cout << Object("newline");
    cout << endl;
    cout << Object("car");
    cout << endl;
    cout << Object("and");
    cout << endl;
    cout << Object("or");
    cout << endl;
    cout << Object("not");
    cout << endl;
    cout << Object("define");
    cout << endl;
    cout << Object("number?");
    cout << endl;
    cout << Object("symbol?");
    cout << endl;
    cout << Object("list?");
    cout << endl;
    cout << Object("zero?");
    cout << endl;
    cout << Object("null?");
    cout << endl;
    cout << Object("char?");
    cout << endl;
    cout << Object("string?");
    cout << endl;
    cout << Object("+");
    cout << endl;
    cout << Object("-");
    cout << endl;
    cout << Object("/");
    cout << endl;
    cout << Object("*");
    cout << endl;
    cout << Object("=");
    cout << endl;
    cout << Object(">");
    cout << endl;
    cout << Object("<");
    cout << endl;
    cout << Object("<=");
    cout << endl;
    cout << Object(">=");
    cout << endl;
    cout << Object(543) ;
    cout << endl;
    return __retVal;
}

int main()
{
    funky(Object("a"));
    return 0;
}

