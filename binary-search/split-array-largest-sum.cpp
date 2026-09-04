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
            int sum=0;
            int count=1;
            for(int i:nums)
            {
                if(sum+i<=maxsum) sum+=i;
                else
                {
                    sum=i;
                    count++;
                }
            }
            return (count<=k);
        }
        int splitArray(vector<int>& nums, int k) 
        {
            int l=0;
            int r=0;
            for(auto i:nums)
            {
                l=max(l,i);
                r+=i;
            }
            int ans=r;
            int mid=l+(r-l)/2;
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if(check(nums,k,mid))
                {
                    r=mid-1;
                    ans=min(mid,ans);
                }
                else
                {
                    l=mid+1;
                }
            }
            return ans;
        }
};