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
        bool stoneGame(vector<int>& piles) 
        {
            //positive for alice negative for bob
            int n=piles.size();
            //-1 not vis 0 means bob wins 1 means alice wins
            vector<vector<int>> dp(n,vector<int>(n,-1));
            //base case?
            for(int i=0;i<n;i++)
            {
                dp[i][i]=piles[i];
            }
            for(int s=n-2;s>=0;s--)
            {
                for(int e=s+1;e<n;e++)
                {
                    int take_start=piles[s] - dp[s+1][e];
                    int take_end=piles[e] - dp[s][e-1];

                    dp[s][e]=max(take_end,take_start);
                }
            }
            return dp[0][n-1]>0;
        }
};