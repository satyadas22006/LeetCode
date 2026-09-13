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
        bool valid(unordered_map<char,int>& curr,unordered_map<char,int>& contain)
        {
            for(auto x:contain)
            {
                if(curr[x.first]<x.second) return false;
            }
            return true;
        }
        string minWindow(string s, string t) 
        {
            int m=s.size();
            int n=t.size();
            unordered_map<char,int> contain;
            for(auto i:t)
            {
                contain[i]++;
            }
            unordered_map<char,int> curr;
            if(t.empty() || n>m) return "";
            int l=0;
            int r=0;
            int ans=INT_MAX;
            pair<int,int> coor={0,0};
            while(r<=m)
            {
                //add right till all added
                if(!valid(curr,contain))
                {
                    if(r==m) break;
                    if(contain.count(s[r]))
                        curr[s[r]]++;
                    r++;
                }
                else 
                {
                    if(r-l<ans)
                    {
                        coor={l,r-1};
                        ans=r-l;
                    }
                    if(contain.count(s[l]))
                        curr[s[l]]--;
                    //l++;
                    
                    l++;
                }
            }
            if(ans==INT_MAX) return "";
            string temp="";
            for(int i=coor.first;i<=coor.second;i++)
            {
                temp+=s[i];
            }
            return temp;
        }
};