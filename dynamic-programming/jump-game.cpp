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
        bool canJump(vector<int>& nums) 
        {
            int max_dist=0;
            for(int i=0;i<nums.size();i++)
            {
                if(i>max_dist)
                {
                    break;
                }
                max_dist=max(max_dist,i+nums[i]);
                if(max_dist>=nums.size()-1)
                {
                    return true;
                }
            }
            return false;
        }
};