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
        int f(int i1,int i2,string a,string b,vector<vector<int>>& dp)
        {
            if(i1<0 || i2<0)
            {
                return 0;
            }

            if(dp[i1][i2]!=-1)
            {
                return dp[i1][i2];
            }
            if(a[i1]==b[i2])
            {
                return dp[i1][i2]=1+f(i1-1,i2-1,a,b,dp);
            }
            // else
            // {
            //     //2 ways 
            //     int x=f(i1-1,i2,a,b,dp);
            //     int y=f(i1,i2-1,a,b,dp);
            //     dp[i1][i2]=max(x,y);
            // }
            return dp[i1][i2]=max(f(i1-1,i2,a,b,dp),f(i1,i2-1,a,b,dp));
        }
        int longestCommonSubsequence(string text1, string text2) 
        {
            int m=text1.size();
            int n=text2.size();
            vector<vector<int>> dp(m,vector<int>(n,-1));
            return f(m-1,n-1,text1,text2,dp);
        }
};