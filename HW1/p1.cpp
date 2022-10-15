#include "p1.h"


void p1::print_usa() {
    cout << "xxx   xxx  xxxx x   xxx" << endl;
    cout << " x     x  x    xx     x" << endl; 
    cout << " x     x  x     x    x x" << endl;
    cout << " x     x  x          x x" << endl; 
    cout << " x     x   xxx      x   x" << endl; 
    cout << " x     x      xx    x   x" << endl; 
    cout << " x     x        x   xxxxx" << endl; 
    cout << " x     x  x     x  x     x" << endl; 
    cout << " xx   xx  xx    x  x     x" << endl; 
    cout << "   xxx    x xxxx  xxx   xxx" << endl; 

}

void p1::print_n_n2_n3() {
  cout <<"n   n^2   n^3" << endl;
  for(int i=1; i<10; i++) {
    int n1 = i, n2 =i*i, n3 = i*i*i;
    int n2space = 5, n3space =5;
    if(n2>=10) {
      n2space = n2space-1;

    }
    if(n3>=100) {
      n3space = n3space-2;
    }
    else if(n3>=10) {
      n3space = n3space-1;
    }

    cout << i;
    for(int j=0; j<n2space; j++) {
      cout << " ";
    }
    cout << i*i;
    for(int j=0; j<n3space; j++) {
      cout << " ";
    }
    cout << i*i*i << endl;
  }

}

void p1::a_power_b() {
  cout << "a  b       a^b" << endl;
  for(int i=1; i<8; i++) {
    int space = 9;
    int c = i;
    int time = i;
    cout << i << "  " << i+1;
    while(time>=1) {
      c = c*i;
      time--;
    }
    int tmp = c;
    while(tmp>=10){
      space--;
      tmp /= 10;
    }
// print space
    for(int j=0; j<space; j++) {
      cout << " ";
    }
    cout << c << endl;

  }

}

void p1::two_power_n() {
  cout << "n        2^n" << endl;
  for(int i=0; i<=20; i++) {
    cout << i;
    int num = 1;
    for(int j=0; j<i; j++) {
      num *= 2;
    }
    int space = 10;
    int tmp = num;
    while(tmp >= 10) {
      space--;
      tmp /=10;
    }
    for(int j=0; j<space; j++) {
      cout << " ";
    }
    cout << num << endl;

  }



}

void p1::a1(int a, int b) {
  for(int i=a; i<=b; i++) {
    for(int j=a; j<=i; j++) {
      if(j == i) {
        cout<< j << endl;
      }
      else {
        cout<< j << "_";
      }
    }
  }


}

void p1::a2(int a, int b) {
  for(int i=a; i<=8; i++) {
    int gap = b-i;
    for(int time = 0; time <gap; time++) {
      cout << "__";
    }
    for(int j=i; j>=a; j--) {
      if(j == a) {
        cout << j << endl;
      }
      else {
        cout << j << "_";
      }
    }
  }

}

void p1::a3(int a, int b) {
  for(int i=b; i>=a; i--) {
    for(int j=a; j<=i; j++) {
      if(j == i) {
        cout << j << endl;
      }
      else {
        cout << j << " ";
      }
    }
  }

}

void p1::a4(int a, int b) {
  for(int i=b; i>=a; i--) {
    int gap = b-i;
    for(int j=0; j<gap; j++) {
      cout << "  ";
    }
    for(int j=a; j<=i; j++) {
      if(j == i) {
        cout << j << endl;
      }
      else {
        cout << j << " ";
      }
    }
  }

}

void p1::riceOnChessBoard(int n) {
  unsigned long long ans = 1;
  unsigned long long total = 0;
  for(int i=1; i<=n; i++) {
    cout << "Rice on Square " << i << " = " << ans << endl;
    total += ans;
    ans *= 2;
  }
  cout << "Total rice = " << total << endl;
}

//EOF