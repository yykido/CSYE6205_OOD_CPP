#pragma once
#include "util.h"

class Array
{
public:
/*----------------------------------------------------------------
Reverse a string
-----------------------------------------------------------------*/
    void copy(char* s, const char* t);
    void p(const string& a, char* s);
    void reverse(char* s);

/*----------------------------------------------------------------
Convert string number to integer
-----------------------------------------------------------------*/
    static int string2number(const char* s);

/*----------------------------------------------------------------
Remove Duplicates
-----------------------------------------------------------------*/
    void p(const string& d, const int* s, int l);
    int removedups(const int* s, int l);
    //void p("AFTER DUP ", const int* s, int k);

private:

};


