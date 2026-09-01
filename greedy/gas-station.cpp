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
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
        {
            int n=gas.size();
            int tank=0;
            int start=0;
            int total=0;
            for(int i=0;i<n;i++)
            {
                total=gas[i]-cost[i];
                tank=gas[i]-cost[i];
                if(tank<0)
                {
                    start=i+1;
                    tank=0;
                }
            }
            return (total>=0)? start:-1;
        }
};