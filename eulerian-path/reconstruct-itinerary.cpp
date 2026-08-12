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
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
        vector<string> ans;
        void dfs(string start)
        {
            while(!adj[start].size())
            {
                string next=adj[start].top();
                adj[start].pop();
                dfs(next);
            }
            ans.push_back(start);
        }
    public:
        vector<string> findItinerary(vector<vector<string>>& tickets) 
        {
            for(auto x:tickets)
            {
                adj[x[0]].push(x[1]);
            }
            dfs("JFK");
            reverse(ans.begin(),ans.end());
            return ans;
        }
};