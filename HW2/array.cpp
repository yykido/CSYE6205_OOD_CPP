#include "array.h"

void Array::reverse(char a[]) {
    int count = 0;
    int index = 0;
    while(a[index] != '\0') {
        count++;
        index++;
    }
    char b[count];
    for(int i=0; i<count; i++) {
        b[count-i-1] = a[i];
    }
    for(int i=0; i<count; i++) {
        a[i] = b[i];
    }

}

int Array::string2number(const char* s) {
    int product = 0;
    int index = 0;
    while(s[index] != '\0') {
        index++;
    }

    for(int i=0; i<index; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            int num = s[i]-'0';
            product *= 10;
            product += num;
        }
        else {
            return 0;
        }
    }
    return product;
}
int Array::removedups(int s[], int l) {
    int a[100];
    int index = 0;
    for(int i=0; i<l; i++) {
        int flag = 0;
        for(int j=0; j<i; j++) {
            if(s[i] == s[j]) {
                flag = 1;
            }
        }
        if(flag == 1) continue;
        a[index++] = s[i];
    }
    memset(s,0,100);
    for(int i=0; i<=index; i++) {
        s[i] = a[i];
    }

    return index;


}

void Array::copy(char a[],const char* b) {
//    memset(a, 0, 100);
    int index = 0;
    while(b[index] != '\0') {
        index++;
    }
    for(int i=0; i<index; i++) {
        a[i] = b[i];
    }
    a[index] = '\0';
}

void Array::p(string s, int b[], int l) {
    cout << s;
    for(int i=0; i<l; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

}

void Array::p(string s, char a[]){
    cout << s << a << endl;
}