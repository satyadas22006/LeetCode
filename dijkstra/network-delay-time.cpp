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
        int networkDelayTime(vector<vector<int>>& times, int n, int k) 
        {
            //start - cost dest
            vector<vector<pair<int,int>>> adj(n+1);
            for(auto x:times)
            {
                adj[x[0]].push_back({x[2],x[1]});
            }
            vector<int> mincost(n+1,INT_MAX);
            //time - dest
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,k});
            mincost[k]=0;
            //int c=n;
            while(!pq.empty())
            {
                auto [cost,dest]=pq.top();
                pq.pop();
                //exception case handled no more further goign
                if(cost>mincost[dest])
                {
                    continue;
                }
                
                for(auto [c,d]:adj[dest])
                {
                    int newcost=cost+c;
                    if(newcost<mincost[d])
                    {
                        mincost[d]=newcost;
                        pq.push({newcost,d});
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(mincost[i]==INT_MAX)
                {
                    return -1;
                }
                ans=max(ans,mincost[i]);
            }

            return ans;
        }
};