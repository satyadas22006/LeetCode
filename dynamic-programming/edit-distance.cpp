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
        // int f(int i,int j,string a,string b,vector<vector<int>> &dp)
        // {
        //     if(i<0) return j+1;
        //     if(j<0) return i+1;
        //     if(dp[i][j]!=-1) return dp[i][j];
        //     if(a[i]==b[j])
        //     {
        //         //equal- no changes needed go next
        //         return dp[i][j]=f(i-1,j-1,a,b,dp);
        //     }
        //     return dp[i][j]=1+min(f(i-1,j-1,a,b,dp),min(f(i-1,j,a,b,dp),f(i,j-1,a,b,dp)));
        // }
        int minDistance(string word1, string word2) 
        {
            if(word1==word2)
            {
                return 0;
            }
            if(word1.size()==0)
            {
                return word2.size();
            }
            if(word2.size()==0)
            {
                return word1.size();
            }
            vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
            for(int i=0;i<=word1.size();i++)
            {
                //0 represents -1
                dp[i][0]=i+1;
            }
            for(int j=0;j<=word2.size();j++)
            {
                dp[0][j]=j+1;
            }
            //1-1 means starting position
            for(int i=1;i<=word1.size();i++)
            {
                for(int j=1;j<=word2.size();j++)
                {
                    if(word1[i]==word2[j])
                    {
                        //if equal then move to next
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        //not equal do some operation
                        dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    }
                }
            }
            return dp[word1.size()][word2.size()];
        }
};
