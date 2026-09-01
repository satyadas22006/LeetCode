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
        bool f(int i,stack<char>& store,string& s,vector<int>& dp)
        {
            if(i>=s.size())
            {
                if(store.size()!=0)
                {
                    return false;
                }
                return true;
            }
            if(s[i]=='*' && dp[i]!=-1)
            {
                return dp[i];
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
                }
                //take it as nothing
                check=check || f(i+1,store,s,dp);
            }
            return check;
        }
        bool checkValidString(string s) 
        {
            stack<char> store;
            vector<int> dp(s.size(),-1);
            return f(0,store,s,dp);
        }
};