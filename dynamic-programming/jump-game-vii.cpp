#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
class Solution 
{
    public:
        bool canReach(string s, int minJump, int maxJump) 
        {
            int n=s.size();
            if(s[n-1]!='0' || s[0]!='0')
            {
                return false;
            }
            vector<int>dp(n,0);
            dp[0]=1;
            int cnt=0;
            for(int i=1;i<n;i++)
            {
                int add=i-minJump;
                if(add>=0 && dp[add]) cnt++;
                int remove=i-maxJump-1;
                if(remove>=0 && dp[remove]) cnt--;
                if(s[i]=='0' && cnt>0)
                {
                    dp[i]=1;
                }
            }
            return dp[n-1];
        }
};