/*----------------------------------------------------------------
Copyright (c) 2020 Author: Jagadeesh Vasudevamurthy
file: ninetynine1.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine1 class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once
#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of ninetynine1 class
-----------------------------------------------------------------*/
class ninetynine1 {
  private:
    const int MAX = 99;
    void _stanzaReference(int n);
    void _stanzaPointer(int n);
    /* write code */
    bool _compute_string(const int n, const char** a, const char** b);
    bool _compute_string(const int n, const char* a, const char* b);

    void _print(const char* a, const char* b, bool b1, const char*  c, const char* d, bool b2);


    const char* bottle[2] = {"bottle","bottles"};
    const char* chars1[10] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    const char* chars2[21] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",""};
    //
  public:
//    explicit ninetynine1(const char **bottle);


    void run();
};


