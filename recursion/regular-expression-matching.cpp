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
            if(i==s.size() && j==p.size())
            {
                return 1;
            }
            if(j==p.size())
            {
                return 0;
            }
            if(i==s.size())
            {
                while(j<p.size())
                {
                    if(p[j]=='*')
                    {
                        j++;
                    }
                    else
                    {
                        return 0;
                    }
                }
                return 1;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            int ans=0;
            if(s[i]==p[j] || p[j]=='.')
            {
                //direct matching
                ans=f(i+1,j+1,s,p,dp);
            }
            else if(p[j]=='*')
            {
                if(j-1>=0 && (s[i]==p[j-1] || p[j-1]=='.'))
                {
                    //2 choices use * and stay at *
                    //or use * zero times, skip *
                    int take=f(i+1,j,s,p,dp);
                    int skip=f(i,j+1,s,p,dp);
                    ans=take || skip;
                }
                else
                {
                    //cant use * so skip it
                    ans=f(i,j+1,s,p,dp);
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