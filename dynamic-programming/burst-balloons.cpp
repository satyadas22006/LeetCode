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
        int maxCoins(vector<int>& nums) 
        {
            //2 things in a state
            //total sum and index, max profit
            nums.insert(nums.begin(),1);
            nums.push_back(1);
            int n=nums.size();
            vector<vector<int>> dp(n,vector<int>(n,0));
            for(int l=n-2;l>=1;l--)
            {
                for(int r=l;r<=n-2;r++)
                {
                    int ans=0;
                    for(int k=l;k<=r;k++)
                    {
                        int coins=nums[l-1]*nums[k]*nums[r+1]+dp[l][k-1]+dp[k+1][r];
                        ans=max(ans,coins);
                    }
                    dp[l][r]=ans;
                }
            }
            return dp[1][n-2];
        }
};