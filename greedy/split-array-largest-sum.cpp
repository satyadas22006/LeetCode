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
        bool check(vector<int>& nums,int k,int maxsum)
        {
            int count=1;
            int sum=0;
            for(int i:nums)
            {
                if(sum+i<=maxsum) sum+=i;
                else
                {
                    count++;
                    sum=i;
                }
            }
            return (count<=k);
        }
        int splitArray(vector<int>& nums, int k) 
        {
            int n=nums.size();
            int l=0;
            int r=0;
            for(auto i:nums)
            {
                l=max(l,i);
                r+=i;
            }
            //l represents max sum if n packets division
            //r represents max sum if 1 packet division
            int ans=r;
            int mid=l+(r-l)/2;
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if(check(nums,k,mid))
                {
                    //if yes that means k groups with maxsum mid can fit
                    //now take even smaller maxsum so more groups
                    ans=min(mid,ans);
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            return ans;
        }
};