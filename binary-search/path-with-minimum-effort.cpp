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
            int m=heights.size();
            int n=heights[0].size();
            vector<vector<int>> mineffort(m,vector<int>(n,INT_MAX));
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
            pq.push({0,{0,0}});
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,-1,1};
            while(!pq.empty())
            {
                auto [effort,node]=pq.top();
                pq.pop();
                int x=node.first;
                int y=node.second;
                if(effort>mineffort[x][y])
                {
                    continue;
                }
                if(x==m-1 && y==n-1)
                {
                    return effort;
                }
                for(int k=0;k<4;k++)
                {
                    int nx=x+dx[k];
                    int ny=y+dy[k];

                    if(nx>=m || ny>=n || nx<0 || ny<0)
                    {
                        continue;
                    }
                    int edge=abs(heights[nx][ny]-heights[x][y]);
                    int h=max(effort,edge);
                    if(h<mineffort[nx][ny])
                    {
                        mineffort[nx][ny]=h;
                        pq.push({h,{nx,ny}});
                    }
                }
            }
            return 0;
        }
};