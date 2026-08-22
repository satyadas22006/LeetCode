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
        int f(int target,int i,vector<int>& stones,vector<vector<int>>& dp)
        {
            if(i>=stones.size())
            {
                return 0;
            }
            if(target==0)
            {
                return 0;
            }   
            //2 options take or not_take
            if(dp[i][target]!=-1)
            {
                return dp[i][target];
            }
            int take=INT_MIN;
            if(stones[i]<=target)
            {
                take=stones[i]+f(target-stones[i],i+1,stones,dp);
            }
            int not_take=f(target,i+1,stones,dp);
            return dp[i][target]=max(take,not_take);
        }
        int lastStoneWeightII(vector<int>& stones) 
        {
            //sort(stones.begin(),stones.end());
            int s=0;
            for(int i:stones)
            {
                s+=i;
            }
            int n=stones.size();
            int target=s/2;
            vector<vector<int>> dp(n,vector<int>(target+1,-1));
            
            return s-2*f(target,0,stones,dp);
        }
};