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
        int minimumEffortPath(vector<vector<int>>& heights) 
        {
            int ans=INT_MIN;
            int m=heights.size(); //rows
            int n=heights[0].size(); //columns

            //effort , row,col

            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
            vector<vector<int>> dist(m,vector<int>(n,INT_MAX)); //min dist to reach the node
            dist[0][0]=0;
            pq.push({0,{0,0}});

            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};

            while(!pq.empty())
            {
                auto [effort,node]=pq.top();
                pq.pop();
                int r=node.first;
                int c=node.second;

                if(r==m-1 && c==n-1)
                {
                    return effort;
                }

                if(effort>dist[r][c])
                {
                    continue;
                }

                for(int k=0;k<4;k++)
                {
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=m || nc>=n || nr<0 || nc<0)
                    {
                        continue;
                    }

                    int edge=abs(heights[nr][nc]-heights[r][c]);
                    int newEffort=max(effort,edge);

                    if(newEffort<dist[nr][nc])
                    {
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
            return 0;
        }
};