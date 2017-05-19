#include <iostream>
#include "Object.h"

using namespace std;

int main()
{
    if ((Object(5)  > Object(6) ))
    {
        cout << Object("five_is_greater_than_six");
    }
    else
    {
                cout << Object("five_is_not_greater_than_six");
    }
    cout << endl;
    if ((Object(5)  < Object(6) ))
    {
        cout << Object("five_is_less_than_six");
    }
    else
    {
                cout << Object("five_is_not_less_than_size");
    }
    cout << endl;
    if ((Object(5)  <= Object(5) ))
    {
        cout << Object("five_is_less_than_or_equal_to_five");
    }
    else
    {
                cout << Object("five_is_not_less_than_or_equal_to_size");
    }
    cout << endl;
    if ((Object(5)  >= Object(5) ))
    {
        cout << Object("five_is_greater_than_or_equal_to_five");
    }
    else
    {
                cout << Object("five_is_not_greater_than_or_equal_to_five");
    }
    cout << endl;
    cout << (Object(1)  + Object(5) );
    cout << endl;
    cout << (Object(-1)  + Object(-5) );
    cout << endl;
    cout << (Object(5)  - Object(7) );
    cout << endl;
    cout << (Object(10)  - Object(32) );
    cout << endl;
    cout << (Object(3)  * Object(7) );
    cout << endl;
    cout << (Object(4)  * Object(32) );
    cout << endl;
    cout << (Object(9)  / Object(3) );
    cout << endl;
    cout << (Object(432)  / Object(43) );
    cout << endl;
    cout << ((Object(15)  - Object(2) ) / (Object(12)  + Object(4) ));
    cout << endl;
    return 0;
}

