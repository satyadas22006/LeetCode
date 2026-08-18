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
        int f(int ind,int amount, vector<vector<int>>& dp,vector<int>& coins)
        {
            if(ind==0)
            {
                if(amount%coins[0]==0)
                {
                    return 1;
                }
                return 0;
            }
            if(dp[ind][amount]!=-1)
            {
                return dp[ind][amount];
            }
            //2 ways take, keeping take till u cant, else dont take
            int nottake=f(ind-1,amount,dp,coins);
            int take=0;

            if(coins[ind]<=amount)
            {
                take=f(ind,amount-coins[ind],dp,coins);
            }

            return dp[ind][amount]=take+nottake;
        }
    public:
        int change(int amount, vector<int>& coins) 
        {
            int n=coins.size()-1;
            vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
            return f(n,amount,dp,coins);       
        }
};