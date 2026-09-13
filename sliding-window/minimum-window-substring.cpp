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
        string minWindow(string s, string t) 
        {
            if(s.empty() || t.empty() || s.length()<t.length()) return "";
            vector<int> map(128,0);
            int count=t.length();
            int l=0;
            int r=0;
            int minlen=INT_MAX;
            int startindex=0;
            for(char c:t) map[c]++;
            while(r<s.length())
            {
                if(map[s[r++]]-- > 0) count--;
                while(count==0)
                {
                    if(r-l<minlen)
                    {
                        startindex=l;
                        minlen=r-l;
                    }
                    if(map[s[l++]]++==0) count++;
                }
            }
            return minlen==INT_MAX ? "" : s.substr(startindex,minlen);
        }
};