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
        int f(int s,int e,vector<int>& piles,vector<vector<int>>& dp)
        {
            if(s==e)
            {
                return piles[s];
            }

            if(dp[s][e]!=-1)
            {
                return dp[s][e];
            }

            int take_start=piles[s] - f(s+1,e,piles,dp);
            int take_end=piles[e] - f(s,e-1,piles,dp);

            return dp[s][e]=max(take_end,take_start);
        }
        bool stoneGame(vector<int>& piles) 
        {
            //positive for alice negative for bob
            int n=piles.size();
            //-1 not vis 0 means bob wins 1 means alice wins
            vector<vector<int>> dp(n,vector<int>(n,-1));
            return f(0,n-1,piles,dp)>0;
            
        }
};