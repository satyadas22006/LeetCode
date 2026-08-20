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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        //1d array solution

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }

        vector<int> dp(n,0); //stores the row

        dp[0]=1;

        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(obstacleGrid[r][c]==1)
                {
                    dp[c]=0;
                }
                else if(c>0)
                {
                    dp[c]=dp[c] + dp[c-1];
                }
            }
        }
        return dp[n-1];
    }
};