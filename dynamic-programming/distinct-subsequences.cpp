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
        int f(int i,int j,string& s,string& t,vector<vector<int>>& dp)
        {
            
            if(j==t.size())
            {
                //i have made it
                return 1;
            }
            if(i>=s.size())
            {
                return 0;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }

            //if index equal then either take or not take
            int take=0;
            int not_take=0;
            if(s[i]==t[j])
            {
                take=f(i+1,j+1,s,t,dp);
                //not_take=f(i+1,j,s,t,dp);
            }
            not_take=f(i+1,j,s,t,dp);
            return dp[i][j]=take+not_take;
        }
        int numDistinct(string s, string t) 
        {
            vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
            return f(0,0,s,t,dp);
        }
};