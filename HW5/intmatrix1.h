//
// Created by yy on 2022/10/13.
//
#pragma once
#include "../util/util.h"

#ifndef HW5_INTMATRIX1_H
#define HW5_INTMATRIX1_H

class intmatrix1 {
private:
    int** pointer;
    int pRow = 0;
    int pCol = 0;

public:
//    void setRow(int a);
//    void setCol(int a);
    int getRow();
    int getCol();
    int** getPointer();
    void init(const char* as);
    void init(int row, int col );
    void init(int row, int col, int value);
    void init();
    void print(const char* str);
    intmatrix1 add(intmatrix1 a);
    intmatrix1 mult(intmatrix1 a);
    void fini();
    bool isEmpty();
    bool isEqual(intmatrix1 s);


};

#endif //HW5_INTMATRIX1_H
