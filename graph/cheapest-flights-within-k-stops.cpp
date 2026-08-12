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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        int tcost=0;
        int stops=0;
        //cost dest stops
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //pq.push({0,src});
    //    vector<int> vis(n,0);

        pq.push({0,{src,0}});
        while(!pq.empty())
        {
            auto [cost,info]=pq.top();
            pq.pop();
            int stops=info.second;
            int dest=info.first;
            if(stops==k+1)
            {
                if(dest==dst)
                {
                    return cost;
                }
                else
                {
                    continue;
                }
            }
            for(auto x:flights)
            {
                if(x[0]==dest)
                {
                    int temp=cost+x[2];
                    pq.push({temp,{x[1],stops+1}});
                }   
            }
        }
        return -1;
    }
};