#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution 
{
    public:
        int firstMissingPositive(vector<int>& nums) 
        {
            int n=nums.size();
            vector<int> temp(n,0);
            for(int i=0;i<n;i++)
            {
                if(nums[i]<=0 || nums[i]>n)
                {
                    continue;
                }
                int x=nums[i]; //valid
                temp[x-1]=x;
            }
            for(int i=0;i<n;i++)
            {
                if(temp[i]!=i+1) return i+1;
            }
            return n+1;
        }
};