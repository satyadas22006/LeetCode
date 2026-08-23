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
        int f(int i,int j,int k,string& s1,string& s2,string& s3,vector<vector<int>>& dp)
        {
            //base case
            if(k>=s3.size())
            {
                return 1;
            }
            if(i>=s1.size() && j>=s2.size())
            {
                return 1;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            int take1=0;
            int take2=0;
            if(i<s1.size() && s1[i]==s3[k])
            {
                take1=f(i+1,j,k+1,s1,s2,s3,dp);
            }
            if(j<s2.size() && s2[j]==s3[k])
            {
                take2=f(i,j+1,k+1,s1,s2,s3,dp);
            }
            return dp[i][j]=take1 || take2;
        }
        bool isInterleave(string s1, string s2, string s3) 
        {
            int x=s1.size();
            int y=s2.size();
            int z=s3.size();
            if(x==0 && y==0)
            {
                if(z==0)
                {
                    return true;
                }
                return false;
            }
            if(x+y<z)
            {
                return false;
            }
            vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
            return (bool)f(0,0,0,s1,s2,s3,dp);
        }
};