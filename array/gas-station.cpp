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
        int f(int count,int intank,int start_index,vector<int>& gas,vector<int>& cost)
        {
            if(count==gas.size())
            {
                return 1;
            }
            int n=gas.size();
            if(intank<cost[start_index])
            {
                return 0;
            }
            int next=(start_index+1)%n;
            int newtank=intank-cost[start_index]+gas[next];
            return f(count+1,newtank,next,gas,cost);
        }
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
        {
            int n=gas.size();
            for(int i=0;i<n;i++)
            {
                //
                if(gas[i]<cost[i])
                    continue;
                else if(f(0,gas[i],i,gas,cost)==1)
                {
                    return i;
                }
            }
            return -1;
        }
};