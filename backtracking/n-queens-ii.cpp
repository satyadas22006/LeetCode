#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;


class Solution 
{
    public:
        void f(int i,int j,int queensleft,vector<vector<int>> marked,int& ans)//,vector<vector<char>>& board)
        {
            if(queensleft==0)
            {
                ans++;
                return;
            }
            int n=marked.size();
            //i and j will be placed a queen
            marked[i][j]=1;
            for(int x=0;x<n;x++)
            {
                marked[i][x]=1;
                marked[x][j]=1;
            }
            int x=i+1;
            int y=j+1;
            while(x<n && y<n)
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
            x=i+1;
            y=j-1;
            while(y>=0 && x<n)
            {
                marked[x][y]=1;
                x++;
                y--;
            }
            x=i-1;
            y=j+1;
            while(x>=0 && y<n)
            {
                marked[x][y]=1;
                x--;
                y++;
            }
            //all cells are marked
            //board[i][j]='Q';
            if(queensleft==1)
            {
                //we have acheived 1 answer!
                ans++;
                return ;
            }
            if(i+1<n)
            {
                for(int nj=0;nj<n;nj++)
                {
                    if(marked[i+1][nj]==0)
                    {
                        f(i+1,nj,queensleft-1,marked,ans);
                    }
                }
            }
        }
        int totalNQueens(int n) 
        {
            //vector<vector<char>> board(n,vector<char>(n,'.'));
            vector<vector<int>> marked(n,vector<int>(n,0));
            int ans=0;
            for(int i=0;i<n;i++)
            {
                //for n rows it each row must have 1 queen
                f(0,i,n,marked,ans);//,board);
            }
            return ans;
        }
};