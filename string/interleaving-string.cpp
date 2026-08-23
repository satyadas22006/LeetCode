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
            if(x+y!=z)
            {
                return false;
            }
            vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
            dp[x][y]=1;
            for(int i=x;i>=0;i--)
            {
                for(int j=y;j>=0;j--)
                {
                    if(i==x && j==y)
                    {
                        continue;
                    }
                    int take1=0;
                    int take2=0;
                    int k=i+j;
                    if(i<x && s1[i]==s3[k])
                    {
                        take1=dp[i+1][j];
                    }
                    if(j<s2.size() && s2[j]==s3[k])
                    {
                        take2=dp[i][j+1];
                    }
                    dp[i][j]=take1 || take2;
                }
            }
            return (bool)dp[0][0];
        }
};