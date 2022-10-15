/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file: Arraytest.cpp

On linux:
g++ Array.cpp Arraytest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test Array object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "array.h"

/*----------------------------------------------------------------
test reverse
-----------------------------------------------------------------*/
static void test_reverse(const char* t) {
  Array a;
  char s[100];
  a.copy(s, t);
  a.p("before ", s);
  a.reverse(s);
  a.p("after  ", s);
}

/*----------------------------------------------------------------
test reverse
-----------------------------------------------------------------*/
static void test_reverse() {
  test_reverse("Hello");
  test_reverse("even");
  test_reverse("Pack my box with five dozen liquor jugs");
}

/*----------------------------------------------------------------
test string2number
-----------------------------------------------------------------*/
static void test_string2number(const char* s) {
  Array a;
  int l = a.string2number(s);
  cout << s << " integer value = " << l << endl;
}

/*----------------------------------------------------------------
test string2number
-----------------------------------------------------------------*/
static void test_string2number() {
  test_string2number("1986");
  test_string2number("19a7");
  test_string2number("19868978");
  test_string2number("");
}

/*----------------------------------------------------------------
test remove dups
-----------------------------------------------------------------*/
static void test_removedups(const int* a, int l) {
  int s[100];
  for (int i = 0; i < l; ++i) {
    s[i] = a[i];
  }
  Array t;
  t.p("BEFORE DUP ", s,l);
  int k = t.removedups(s, l);
  t.p("AFTER DUP ", s,k);
}

/*----------------------------------------------------------------
test remove dups
-----------------------------------------------------------------*/
static void test_removedups() {
  {
    int a[] = { 5, 2, 9, 3, 7 };
    int l = sizeof(a) / sizeof(int);
    test_removedups(a, l);
  }
  {
    int a[] = { 2, 2 };
    int l = sizeof(a) / sizeof(int);
    test_removedups(a, l);
  }
  {
    int a[] = { 58, 26, 91, 26, 70, 70, 91, 58, 58, 58, 66 };
    int l = sizeof(a) / sizeof(int);
    test_removedups(a, l);
  }
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
  test_reverse();
  test_string2number();
  test_removedups();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { //mainarray
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  testbed() ;
  return 0 ;
}

//EOF
