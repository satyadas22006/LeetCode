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
        int swimInWater(vector<vector<int>>& grid) 
        {
            int n=grid.size();
            //stores height and node
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
            pq.push({0,{0,0}});
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};

            vector<vector<int>> mintime(n,vector<int>(n,INT_MAX));
            while(!pq.empty())
            {
                auto [time,node]=pq.top();
                pq.pop();
                int x=node.first;
                int y=node.second;
                if(x==n-1 && y==n-1 && grid[x][y]<=time)
                {
                    return time;
                }
                if(time>mintime[x][y])
                {
                    continue;
                }

                for(int k=0;k<4;k++)
                {
                    int nx=x+dx[k];
                    int ny=y+dy[k];

                    if(nx>=n || ny>=n || nx<0 || ny<0)
                    {
                        continue;
                    }
                    int newtime=max(time,grid[nx][ny]);
                    if(newtime<mintime[nx][ny])
                    {
                        mintime[nx][ny]=newtime;
                        pq.push({newtime,{nx,ny}});
                    }
                }
            }
            return 0;
        }
};