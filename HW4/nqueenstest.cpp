/*----------------------------------------------------------------
Copyright (c) 2013 Author: Jagadeesh Vasudevamurthy
file: nqueenstest.cpp

On linux:
g++ nqueens.cpp nqueenstest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test nqueens object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "nqueens.h"

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
  nqueens a ;
  a.q4() ;
  a.q8() ;
  //a.nqueen_recurrsive(4) ;
  //a.nqueen_recurrsive(8) ;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { //mainnqueens
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  testbed() ;
  return 0 ;
}

//EOF


