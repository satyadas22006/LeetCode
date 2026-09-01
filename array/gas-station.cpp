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
            if(count>=gas.size())
            {
                return 1;
            }
            if(start_index>=gas.size())
            {
                start_index%=gas.size();
            }
            if(cost[start_index]>intank)
            {
                return 0;
            }
            else
            {
                int res=f(count+1,intank-cost[start_index],start_index+1,gas,cost);
                if(res==1)
                {
                    return 1;
                }
            }
            return 0;
        }
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
        {
            int n=gas.size();
            for(int i=0;i<n;i++)
            {
                //
                if(gas[i]<cost[i])
                    continue;
                if(f(1,gas[i],i,gas,cost))
                {
                    return i;
                }
            }
            return -1;
        }
};