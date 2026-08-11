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
        int minCostConnectPoints(vector<vector<int>>& points) 
        {
            //vector<vector<int>> adj(points.size(),vector<int>(points.size(),0));
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            //vector<vector<int>> vis(points.size(),vector<int>(points.size(),0));
            //pq stores the cost to reach x,y node
            vector<int> vis(points.size(),0);
            pq.push({0,0});
            //make adj list
            // /pq.push({0,{points[0][0],points[0][1]}});
            int ans=0;
            while(!pq.empty())
            {
                auto [wt,node]=pq.top();
                pq.pop();
                if(vis[node])
                {
                    continue;
                }

                vis[node]=1;
                ans+=wt;

                for(int i=0;i<points.size();i++)
                {
                    if(!vis[i])
                    {
                        int cost=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                        pq.push({cost,i});
                    }
                }
            }
            return ans;
        }
};