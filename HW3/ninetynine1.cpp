/*----------------------------------------------------------------
Copyright (c) 2020 Author: Jagadeesh Vasudevamurthy
file: ninetynine1.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine1 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine1.h"
/*----------------------------------------------------------------
Ninety nine bottles of beer on the wall,
Ninety nine bottles of beer,
Take one down, pass it around,
Ninety eight bottles of beer on the wall.

One bottle of beer on the wall,
One bottle of beer,
Take one down, pass it around,
Zero bottle of beer on the wall.
(91)
a = Ninety
b = one
(90)
c = Ninety
d = ""
*----------------------------------------------------------------*/
void ninetynine1::_print(const char* a, const char* b, bool b1, const char*  c, const char* d, bool b2) {
  //NOTHING CAN BE CHANGED
  const char* bot = bottle[b1];
  cout << a << " " << b << " " << bot << " of beer on the wall," << endl;
  cout << a << " " << b << " " << bot << " of beer," << endl;
  cout << "Take one down, pass it around," << endl;
  bot = bottle[b2];
  cout << c << " " << d << " " << bot << " of beer on the wall," << endl;
  cout << endl;
}

/*----------------------------------------------------------------
compute strings pointer based
*----------------------------------------------------------------*/
bool ninetynine1::_compute_string(const int n, const char** a, const char** b) {
  bool plural = true;
  //WRITE CODE
  if(n != 1) {
      plural = false;
  }



  return plural;
}

bool ninetynine1::_compute_string(const int n, const char *a, const char *b) {
    bool plural = true;
    if(n == 1) {
        plural = false;
    }


    return plural;

}

/*----------------------------------------------------------------
compute strings using Reference
*----------------------------------------------------------------*/
void ninetynine1::_stanzaReference(int n) {
  /* WRITE CODE */
  int num1 = n/10;
  int num2 = n%10;

  if(num1 == 1) {
      num2 += 10;
  }
  else if(num1 > 1 && n%10 == 0) {
      num2 = 20;
  }


  int num3 = (n-1)/10;
  int num4 = (n-1)%10;
  if(num3 == 1) {
      num4 += 10;
  }
  else if(num3>1 && (n-1)%10 == 0) {
      num4 = 20;
  }
//
//  if(n == 1) {
//      num2 = 0;
//      num4 = 0;
//  }

  const char* a = chars1[num1];
  const char* b = chars2[num2];
  const char* c = chars1[num3];
  const char* d = chars2[num4];

  //

  bool b1 = _compute_string(n,&a,&b);
  bool b2 = _compute_string(n - 1,&c,&d);
  _print(a, b, b1, c, d, b2);
}

/*----------------------------------------------------------------
compute strings using Pointers
*----------------------------------------------------------------*/
void ninetynine1::_stanzaPointer(int n) {
    /* WRITE CODE */

    int num1 = n/10;
    int num2 = n%10;

    if(num1 == 1) {
        num2 += 10;
    }
    else if(num1 > 1 && n%10 == 0) {
        num2 = 20;
    }


    int num3 = (n-1)/10;
    int num4 = (n-1)%10;
    if(num3 == 1) {
        num4 += 10;
    }
    else if(num3>1 && (n-1)%10 == 0) {
        num4 = 20;
    }

    const char* a = chars1[num1];
    const char* b = chars2[num2];
    const char* c = chars1[num3];
    const char* d = chars2[num4];

  bool b1 = _compute_string(n, /* INTERFACE WRITE CODE*/a,b);
  bool b2 = _compute_string(n - 1, /* INTERFACE WRITE CODE*/c,d);

  _print(a, b, b1, c, d, b2);
}

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED BELOW
*----------------------------------------------------------------*/
void ninetynine1::run() {
  cout << "Reference based song\n";
  for (int i = MAX; i > 0; --i) {
    _stanzaReference(i);
  }
  cout << "Pointer based song\n";
  for (int i = MAX; i > 0; --i) {
    _stanzaPointer(i);
  }
}




//EOF


