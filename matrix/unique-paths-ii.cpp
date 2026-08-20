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
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Starting cell
        if(obstacleGrid[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                // Skip starting cell
                if(r == 0 && c == 0)
                    continue;

                // Obstacle
                if(obstacleGrid[r][c] == 1)
                {
                    dp[r][c] = 0;
                    continue;
                }

                int up = 0;
                int left = 0;

                if(r > 0)
                    up = dp[r-1][c];

                if(c > 0)
                    left = dp[r][c-1];

                dp[r][c] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};