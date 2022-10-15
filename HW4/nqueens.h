//
// Created by yy on 2022/10/6.
//
#pragma once
#include "../util/util.h"
#ifndef HW4_NQUEEN_H
#define HW4_NQUEEN_H


class nqueens {
public:
    void q4();
    void q8();
    bool isvalid(int row,int col,vector<string>&grid,int n);
    void dfs(int col,vector<vector<string>>&ans,vector<string>&grid,int n);
    vector<vector<string>> solveNQueens(int n);



};


#endif //HW4_NQUEEN_H
