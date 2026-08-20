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
        int minPathSum(vector<vector<int>>& grid) 
        {
            int m=grid.size();
            int n=grid[0].size();
            //stores the minimal sum
            vector<vector<int>> dp(m,vector<int>(n,-1));
            //make the base case
            dp[0][0]=grid[0][0];
            for(int r=0;r<m;r++)
            {
                for(int c=0;c<n;c++)
                {
                    if(r==0 && c==0)
                    {
                        continue;
                    }
                    int dw=INT_MAX;
                    if(c>0)
                    {
                        dw=dp[r][c-1];
                    }
                    int rg=INT_MAX;
                    if(r>0)
                    {
                        rg=dp[r-1][c];
                    }
                    dp[r][c]=grid[r][c] + min(dw,rg);
                }
            }
            return dp[m-1][n-1];
        }
};