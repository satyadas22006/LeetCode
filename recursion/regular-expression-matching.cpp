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
        int f(int i,int j,string& s,string& p,vector<vector<int>> &dp)
        {
            if(i==s.size())
            {
                //s bangya
                return 1;
            }
            if(j==p.size())
            {
                //s nhi bana but p khtm hogya
                return 0;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            int ans=0;
            if(s[i]==p[j])
            {
                //direct matching
                ans=ans || f(i+1,j+1,s,p,dp);
            }
            if(p[j]=='.')
            {
                //cud be anything nice move to next
                ans=ans || f(i+1,j+1,s,p,dp);
            }
            if(p[j]=='*')
            {
                if(j-1>=0 && (s[i]==p[j-1] || p[j-1]=='.'))
                {
                    ans= ans || f(i+1,j,s,p,dp);
                }
            }
            return dp[i][j]=ans;
        }
        bool isMatch(string s, string p) 
        {
            int m=s.size();
            int n=p.size();
            vector<vector<int>> dp(m,vector<int>(n,-1));
            return f(0,0,s,p,dp);
        }
};