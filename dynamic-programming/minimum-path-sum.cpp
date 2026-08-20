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
            vector<int> dp(n,0);
            //make the base case
            dp[0]=grid[0][0];
            for(int r=0;r<m;r++)
            {
                for(int c=0;c<n;c++)
                { 
                    if(r==0 && c==0)
                    {
                        continue;
                    }
                    int up=INT_MAX;
                    int lf=INT_MAX;
                    if(r>0) up=dp[c];
                    if(c>0) lf=dp[c-1];
                    dp[c]=grid[r][c] + min(up,lf);
                }
            }
            return dp[n-1];
        }
};