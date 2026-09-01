#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
class Solution 
{
    public:
        bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
        {
            unordered_set<int> blacklist;
            for(int i=0;i<triplets.size();i++)
            {
                if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2])
                {
                    blacklist.insert(i);
                }
            }
            int max1=0;
            int max2=0;
            int max3=0;
            for(int i=0;i<triplets.size();i++)
            {
                if(blacklist.count(i))
                {
                    continue;
                }
                max1=max(max1,triplets[i][0]);
                if(max1>target[0]) return false;
                max2=max(max2,triplets[i][1]);
                if(max2>target[1]) return false;
                max3=max(max3,triplets[i][2]);
                if(max3>target[2]) return false;
            }
            if(max1!=target[0] || max2!=target[1] || max3!=target[2])   return false;
            return true;            
        }
};