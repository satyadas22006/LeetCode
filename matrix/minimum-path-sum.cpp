#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <math.h>
using namespace std;

class Solution 
{
    public:
        int f(int r,int c,int m,int n,vector<vector<int>>& dp,vector<vector<int>>& grid)
        {
            if(r<0 || c<0 || r>=m || c>=n)
            {
                return INT_MAX;
            }
            //base case
            if(r==m-1 && c==n-1)
            {
                return grid[r][c];
            }
            if(dp[r][c]!=-1)
            {
                return dp[r][c];
            }
            
            //go down
            int dw =f(r+1,c,m,n,dp,grid);
            //go right
            int rt=f(r,c+1,m,n,dp,grid);
            return dp[r][c]=grid[r][c]+min(dw,rt);
        }
        int minPathSum(vector<vector<int>>& grid) 
        {
            int m=grid.size();
            int n=grid[0].size();
            //stores the minimal sum
            vector<vector<int>> dp(m,vector<int>(n,-1));
            return f(0,0,m,n,dp,grid);
        }
};