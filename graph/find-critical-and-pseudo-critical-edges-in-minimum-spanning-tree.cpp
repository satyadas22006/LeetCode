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
        vector<int> parent,rank;

        int find(int x)
        {
            if(parent[x]==x)
            {
                return x;
            }
            return parent[x]=find(parent[x]);
        }

        bool unite(int u,int v)
        {
            int pu=find(u);
            int pv=find(v);

            if(pu==pv)
            {
                return false;
            }

            if(rank[pu]<rank[pv])
            {
                parent[pu]=pv;
            }
            else if(rank[pu]>rank[pv])
            {
                parent[pv]=pu;
            }
            else
            {
                parent[pu]=pv;
                rank[pv]++;
            }

            return true;
        }

        int cost_mst(int n,vector<int>& skip,
                     vector<vector<int>>& edges)
        {
            parent.resize(n);
            rank.assign(n,0);

            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }

            int cost=0;
            int count=0;

            for(auto &e:edges)
            {
                if(e==skip)
                {
                    continue;
                }

                int x=e[0];
                int y=e[1];
                int w=e[2];

                if(unite(x,y))
                {
                    cost+=w;
                    count++;

                    if(count==n-1)
                    {
                        break;
                    }
                }
            }

            if(count!=n-1)
            {
                return INT_MAX;
            }

            return cost;
        }

        vector<vector<int>> findCriticalAndPseudoCriticalEdges(
            int n,vector<vector<int>>& edges) 
        {
            // original index
            for(int i=0;i<edges.size();i++)
            {
                edges[i].push_back(i);
            }

            sort(edges.begin(),edges.end(),
                [](vector<int>& a,vector<int>& b)
                {
                    return a[2]<b[2];
                });

            vector<vector<int>> ans(2);
            vector<int> temp={-1,-1,-1,-1};
            int min_cost=cost_mst(n,temp,edges);

            for(int i=0;i<edges.size();i++)
            {
                // REMOVE edge
                int newcost=cost_mst(n,edges[i],edges);

                if(newcost>min_cost)
                {
                    // critical
                    ans[0].push_back(edges[i][3]);
                    continue;
                }

                // FORCE edge i
                parent.resize(n);
                rank.assign(n,0);

                for(int j=0;j<n;j++)
                {
                    parent[j]=j;
                }

                int cost=edges[i][2];
                int count=1;

                unite(edges[i][0],edges[i][1]);

                for(auto &e:edges)
                {
                    if(e==edges[i])
                    {
                        continue;
                    }

                    if(unite(e[0],e[1]))
                    {
                        cost+=e[2];
                        count++;

                        if(count==n-1)
                        {
                            break;
                        }
                    }
                }

                if(cost==min_cost)
                {
                    // pseudo-critical
                    ans[1].push_back(edges[i][3]);
                }
            }

            return ans;
        }
};