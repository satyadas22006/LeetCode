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
        int f(int i,int j,string a,string b,vector<vector<int>> &dp)
        {
            if(i<0)
            {
                return j+1;
            }
            if(j<0)
            {
                return i+1;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            if(a[i]==b[j])
            {
                return dp[i][j]=f(i-1,j-1,a,b,dp);
            }
            else
            {
                //3 posibilities
                return dp[i][j]=1+min(f(i-1,j-1,a,b,dp),min(f(i-1,j,a,b,dp),f(i,j-1,a,b,dp)));
            }
        }
        int minDistance(string word1, string word2) 
        {
            vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
            return f(word1.size()-1,word2.size()-1,word1,word2,dp);
        }
};