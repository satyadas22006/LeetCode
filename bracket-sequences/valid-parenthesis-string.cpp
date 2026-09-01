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
        bool f(int i,stack<char> store,string& s,vector<vector<int>>& dp)
        {
            if(i>=s.size())
            {
                if(store.size()!=0)
                {
                    return false;
                }
                return true;
            }
            if(dp[i][store.size()]!=-1)
            {
                return dp[i][store.size()];
            }
            bool check=false;
            if(s[i]=='(')
            {
                store.push(s[i]);
                check=check || f(i+1,store,s,dp);
            }
            else if(s[i]==')')
            {
                if(store.size())
                {
                    store.pop();
                }
                check= check || f(i+1,store,s,dp);
            }
            else if(s[i]=='*')
            {
                //take 3 possibilities
                //take it as (
                store.push('(');
                check=check || f(i+1,store,s,dp);
                store.pop();
                //take it as )
                if(store.size())
                {
                    store.pop();
                    check=check || f(i+1,store,s,dp);
                    store.push('(');
                }
                //take it as nothing
                check=check || f(i+1,store,s,dp);
            }
            return dp[i][store.size()]=check;
        }
        bool checkValidString(string s) 
        {
            stack<char> store;
            vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
            return f(0,store,s,dp);
        }
};