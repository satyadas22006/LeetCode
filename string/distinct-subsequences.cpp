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
        int numDistinct(string s, string t) 
        {
            vector<vector<long long>> dp(s.size()+1,vector<long long>(t.size()+1,0));
            for(int i=0;i<=s.size();i++)
            {
                dp[i][t.size()]=1;
            }
            for(int i=s.size()-1;i>=0;i--)
            {
                for(int j=t.size()-1;j>=0;j--)
                {
                    int take=0;
                    int not_take=dp[i+1][j];
                    if(s[i]==t[j])
                    {
                        take=dp[i+1][j+1];
                    }

                    dp[i][j]=take+not_take;
                }
            }
            return dp[0][0];
        }
};