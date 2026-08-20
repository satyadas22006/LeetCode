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
        int f(int r,int c,int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid)
        {
            if(r<0 || c<0 || r>=m || c>=n)
            {
                return 0;
            }
            if(obstacleGrid[r][c]==1)
            {
                return 0;
            }
            
            if(r==m-1 && c==n-1)
            {
                return 1;
            }
            if(dp[r][c]!=-1)
            {
                return dp[r][c];
            }
            int btm=f(r+1,c,m,n,dp,obstacleGrid);
            int rgt=f(r,c+1,m,n,dp,obstacleGrid);
            return dp[r][c]=btm + rgt;
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
        {
            int m=obstacleGrid.size();
            int n=obstacleGrid[0].size();
            vector<vector<int>> dp(m,vector<int>(n,-1));
            return f(0,0,m,n,dp,obstacleGrid);
        }
};