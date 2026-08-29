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
        int f(int start,int &minJump,int &maxJump,string &s,vector<int>& dp)
        {
            if(start>=s.size()-1)
            {
                return true;
            }
            if(dp[start]!=-1)
            {
                return dp[start];
            }
            int l=start+minJump;
            int r=min((int)s.size()-1,start+maxJump);
            //bool check=false;
            for(int i=l;i<=r;i++)
            {
                if(s[i]=='0')
                {
                    //check=true;
                    int res=f(i,minJump,maxJump,s,dp);
                    if(res)
                    {
                        return dp[start]=1;
                    }
                }
            }
            return dp[start]=0;
        }
        bool canReach(string s, int minJump, int maxJump) 
        {
            vector<int> dp(s.size(),-1);
            if(s[0]!='0' || s.back()!='0')
            {
                return false;
            }
            //starts with 0 fs
            return (bool)f(0,minJump,maxJump,s,dp);
        }
};