#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;


class Solution 
{
    public:
        int f(bool firsttaken,int i,vector<int>& nums,vector<vector<int>>& dp)
        {
            if(firsttaken && i==nums.size()-1)
            {
                return 0;
            }
            if(i>=nums.size())
            {
                return 0;
            }
            if(dp[i][firsttaken]!=-1)
            {
                return dp[i][firsttaken];
            }
            int skip=f(firsttaken,i+1,nums,dp);
            int take=0;
            if(i==0)
                take=nums[i]+f(true,i+2,nums,dp);
            else
                take=nums[i]+f(firsttaken,i+2,nums,dp);
            dp[i][firsttaken]=max(take,skip);
            return dp[i][firsttaken];
        }
    public:
        int rob(vector<int>& nums) 
        {
            if(nums.size()==1)
            {
                return nums[0];
            }
            if(nums.size()==2)
            {
                return max(nums[0],nums[1]);
            }
            bool firsttaken=false;
            int n=nums.size();
            vector<vector<int>> dp(n+2,vector<int>(2,-1));
            int ans=0;
            return f(firsttaken,0,nums,dp);
        }
};