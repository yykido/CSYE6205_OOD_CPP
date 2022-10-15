//
// Created by yy on 2022/10/6.
//

#include "nqueens.h"

void nqueens::q4() {
    vector<vector<string>> answer = solveNQueens(4);
    int i=1;
    for( auto const& string_vec : answer ){
        cout<< "SOLUTION " << i <<endl;
        i++;
        for( auto const& s : string_vec )
            cout << s << endl;
    }


}

void nqueens::q8() {
    vector<vector<string>> answer = solveNQueens(8);
    int i=1;
    for( auto const& string_vec : answer ) {
        cout<< "SOLUTION " << i <<endl;
        i++;
        for( auto const& s : string_vec )
            cout << s << endl;
    }
}


bool nqueens::isvalid(int row,int col,vector<string>&grid,int n)
{
    for(int i=0;i<col;i++)
    {
        if(grid[row][i]=='1') return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(grid[i][j]=='1') return false;
    }
    for(int i=row,j=col;i<n && j>=0;i++,j--)
    {
        if(grid[i][j]=='1') return false;
    }
    return true;
}

void nqueens::dfs(int col,vector<vector<string>>&ans,vector<string>&grid,int n)
{
    if(col==n)
    {
        ans.push_back(grid);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(isvalid(row,col,grid,n))
        {
            grid[row][col]='1';
            dfs(col+1,ans,grid,n);
            grid[row][col]='-';
        }
    }
}
vector<vector<string>> nqueens::solveNQueens(int n) {
    vector<string>grid(n,string(n,'-'));
    vector<vector<string>>ans;
    int col=0;
    dfs(col,ans,grid,n);
    return ans;
}
