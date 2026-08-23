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
        int f(int l,int r,vector<vector<int>> &dp,vector<int>& nums)
        {
            if(l>r)
            {
                return 0;
            }
            if(dp[l][r]!=-1)
            {
                return dp[l][r];
            }
            int k=l+(r-l)/2;
            int ans=0;
            for(int k=l;k<=r;k++)
            {
                int coins=nums[l-1]*nums[k]*nums[r+1]+f(l,k-1,dp,nums)+f(k+1,r,dp,nums);
                ans=max(ans,coins);
            }
            return dp[l][r]=ans;
        }
        int maxCoins(vector<int>& nums) 
        {
            //2 things in a state
            //total sum and index, max profit
            nums.insert(nums.begin(),1);
            nums.push_back(1);
            int n=nums.size();
            vector<vector<int>> dp(n,vector<int>(n,-1));

            return f(1,n-2,dp,nums);
        }
};