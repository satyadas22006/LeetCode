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
        vector<int> partitionLabels(string s) 
        {
            unordered_map<char,int> mp;
            for(int i=0;i<s.size();i++)
            {
                //char -> index mapping
                mp[s[i]]=i;
            }
            int maxlen=0;
            int start=0;
            vector<int> ans;
            for(int i=0;i<s.size();i++)
            {
                maxlen=max(maxlen,mp[s[i]]);
                if(maxlen==i)
                {
                    ans.push_back(maxlen-start+1);
                    start=i+1;
                }
            }
            return ans;
        }
};