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
        bool f(int i,int store,string& s,vector<vector<int>>& dp)
        {
            if(i>=s.size())
            {
                if(store!=0)
                {
                    return false;
                }
                return true;
            }
            int sz=store;
            if(dp[i][sz]!=-1)
            {
                return dp[i][sz];
            }
            bool check=false;
            if(s[i]=='(')
            {
                //store.push(s[i]);
                check=check || f(i+1,store+1,s,dp);
            }
            else if(s[i]==')')
            {
                if(store)
                {
                    store--;
                }
                else
                {
                    return false;
                }
                check= check || f(i+1,store,s,dp);
            }
            else if(s[i]=='*')
            {
                //take 3 possibilities
                //take it as (
                store++;
                check=check || f(i+1,store,s,dp);
                store--;
                //take it as )
                if(store)
                {
                    store--;
                    check=check || f(i+1,store,s,dp);
                    store++;
                }
                //take it as nothing
                check=check || f(i+1,store,s,dp);
            }
            return dp[i][sz]=check;
        }
        bool checkValidString(string s) 
        {
            if(s[0]==')') return false;
            if(s[s.size()-1]=='(') return false;
            //stack<char> store;
            vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
            return f(0,0,s,dp);
        }
};