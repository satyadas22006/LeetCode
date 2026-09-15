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
            //vector<int> temp(n,0);
            for(int i=0;i<n;i++)
            {
                while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
                {   
                    //int x=nums[i]; //x=3, swap 3rd index and i
                    swap(nums[i],nums[nums[i]-1]);
                }
            }
            for(int i=0;i<n;i++)
            {
                if(nums[i]!=i+1) return i+1;
            }
            return n+1;
        }
};