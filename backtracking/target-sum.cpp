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
        // int f(int i,int target,vector<int>& nums,vector<unordered_map<int,int>> &dp)
        // {
        //     //plus or minus the index
        //     if(i>=nums.size())
        //     {
        //         return target==0;
        //     }
        //     if(dp[i].count(target))
        //     {
        //         return dp[i][target];
        //     }
        //     int plus=f(i+1,target-nums[i],nums,dp);
        //     int minus=f(i+1,target+nums[i],nums,dp);
        //     return dp[i][target]=plus+minus;
       // }
        int findTargetSumWays(vector<int>& nums, int target) 
        {
            int n=nums.size();
            vector<unordered_map<int,int>> dp(n+1);
            dp[n][0]=1;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];
            }
            if(abs(target)>sum)
            {
                return 0;
            }
            for(int i=n-1;i>=0;i--)
            {
                for(auto &p:dp[i+1])
                {
                    int j=p.first;
                    int ways=p.second;
                    dp[i][j+nums[i]]+=ways;
                    dp[i][j-nums[i]]+=ways;
                }
            }
            return dp[0][target];
        }
};