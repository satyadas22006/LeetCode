#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution 
{
    public:
        void f(int start,int i,string s,unordered_set<string>& mp,vector<string>& ans)
        {
            if(i>=s.size())
            {
                //add the ans
                //ans.push_back(s);
                return;
            }
            string a=s.substr(start,i-start+1);
            if(mp.count(a))
            {
                if(i==s.size()-1)
                {
                    //this is the last element and there is a count then add it
                    ans.push_back(s);
                    return;
                }
                //then this substring exists
                //skip it
                f(start,i+1,s,mp,ans);
                //taking it
                s.insert(i+1," ");
                f(i+2,i+2,s,mp,ans);

            }
            else
            {
                f(start,i+1,s,mp,ans);
            }

        }
        vector<string> wordBreak(string s, vector<string>& wordDict) 
        {
            vector<string> ans;
            unordered_set<string> mp;
            for(auto i:wordDict)
            {
                mp.insert(i);
            }
            f(0,0,s,mp,ans);
            return ans;
        }
};