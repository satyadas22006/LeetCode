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

class Solution {
public:
    int f(int i,int state,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(dp[i][state]!=-1)
        {
            return dp[i][state];
        }

        if(state==0)
        {
            //rested with no stock 
            //rest again
            //buy smth
            int rest=f(i+1,0,prices,dp);
            int buy=-prices[i]+f(i+1,1,prices,dp);
            return dp[i][state]=max(rest,buy); 
        }
        else if(state==1)
        {
            //have stcok
            //rest or sell
            int hold=f(i+1,1,prices,dp);
            int sell=prices[i]+f(i+1,2,prices,dp);
            return dp[i][state]=max(hold,sell);
        }
        //once sold go and rest
        return dp[i][state]=f(i+1,0,prices,dp);
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        //0-rest
        //1-bought
        //2-just sold
        return f(0,0,prices,dp);    
    }
};