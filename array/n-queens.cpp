#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    void f(int i,int j,int queensleft,vector<vector<int>> marked,vector<vector<char>>&board,vector<vector<string>>& ans)
    {
        //you can only add somwhere if that place is not marked yet
        //add i and j queen
        //marking everyhing
        if(queensleft==0)
        {
            vector<string> temp;
            for(int x = 0; x < board.size(); x++)
            {
                string row = "";
                for(int y = 0; y < board.size(); y++)
                {
                    row += board[x][y];
                }
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }
        if(marked[i][j]==1) return;
        for(int x=0;x<board.size();x++)
            marked[x][j]=1;
        for(int x=0;x<board.size();x++)
            marked[i][x]=1;
        marked[i][j]=1;
        //now diagonals
        int x=i+1;
        int y=j+1;
        while(x<board.size() && y<board.size())
        {
            marked[x][y]=1;
            x++;
            y++;
        }
        x=i-1;
        y=j-1;
        while(x>=0 && y>=0)
        {
            marked[x][y]=1;
            x--;
            y--;
        }
        // Down-left diagonal
        x = i + 1;
        y = j - 1;
        while(x < board.size() && y >= 0)
        {
            marked[x][y] = 1;
            x++;
            y--;
        }
        // Up-right diagonal
        x = i - 1;
        y = j + 1;
        while(x >= 0 && y < board.size())
        {
            marked[x][y] = 1;
            x--;
            y++;
        }
        board[i][j]='Q';
        if(queensleft==1)
        {
            vector<string> temp;

            for(int x=0;x<board.size();x++)
            {
                string row="";

                for(int y=0;y<board.size();y++)
                {
                    row += board[x][y];
                }

                temp.push_back(row);
            }

            ans.push_back(temp);

            board[i][j]='.';
            return;
        }
        //all are marked if and only if i and j has queen placed
        if(i+1 < board.size())
        {
            for(int nj=0;nj<board.size();nj++)
            {
                if(marked[i+1][nj]==0)
                {
                    f(i+1,nj,queensleft-1,marked,board,ans);
                }
            }
        }
        board[i][j]='.';
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        //dp state being index 2d matrix and queens left
        //make the board
        vector<vector<char>> board(n,vector<char>(n,'.'));
        //currently empty
        //making a marked 2d array
        //0 unmarked and 1 marked
        //int totalboxes=n*n;
        vector<vector<int>> marked(n,vector<int>(n,0));
        vector<vector<string>> ans;
        for(int j=0;j<n;j++)
        {
            f(0,j,n,marked,board,ans);
        }        
        return ans;
    }
};