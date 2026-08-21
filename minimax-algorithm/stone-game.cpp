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
        int f(int tracker,int s,int e,vector<int>& piles,vector<vector<int>>& dp)
        {
            if(s>e)
            {
                return 0;
            }
            if(dp[s][e]!=-1)
            {
                //visited already
                return dp[s][e];
            }
            int take_start_sum, take_end_sum;
            take_end_sum==INT_MIN;
            take_start_sum==INT_MIN;
            int check=tracker%2;
            if(piles[s]>=piles[e] && tracker==0)
            {
                //take start
                take_start_sum=piles[s]+f(tracker+1,s+1,e,piles,dp);
            }
            else if(piles[s]>=piles[e] && tracker==1)
            {
                //take end
                take_end_sum=piles[e]+f(tracker+1,s+1,e-1,piles,dp);
            }
            else if(piles[s]<piles[e] && tracker==0)
            {
                take_end_sum=piles[e]+f(tracker+1,s,e-1,piles,dp);
            }
            else
            {
                take_start_sum=piles[s]+f(tracker+1,s+1,e-1,piles,dp);
            }

            return dp[s][e]=max(take_end_sum,take_start_sum);
        }
        bool stoneGame(vector<int>& piles) 
        {
            //positive for alice negative for bob
            int n=piles.size();
            int total=0;
            for(int i:piles)
            {
                total+=i;
            }
            //-1 not vis 0 means bob wins 1 means alice wins
            vector<vector<int>> dp(n,vector<int>(n,-1));
            int res=f(0,0,n-1,piles,dp);
            return (bool) res;
        }
};