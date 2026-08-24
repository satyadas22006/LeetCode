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
            if(j==p.size())
            {
                return i==s.size();
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            int ans=0;
            bool match=false;
            if(i<s.size() &&(s[i]==p[j] || p[j]=='.'))
            {
                match=true;
            }  
            if(j+1<p.size() && p[j+1]=='*')
            {
                int skip=f(i,j+2,s,p,dp);
                int take=0;
                if(match)
                {
                    take=f(i+1,j,s,p,dp);
                }
                ans=skip || take;
            }
            else
            {
                if(match)
                {
                    ans=f(i+1,j+1,s,p,dp);
                }
            }
            return dp[i][j]=ans;
        }
        bool isMatch(string s, string p) 
        {
            int m=s.size();
            int n=p.size();
            vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
            return f(0,0,s,p,dp);
        }
};