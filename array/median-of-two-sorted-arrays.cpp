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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        int sum=m+n;
        int i=0,j=0;
        double ans=INT_MIN;
        bool check=sum%2;
        if(check) //false if even true if odd
        {
            sum=sum/2;
        }
        else
        {
            sum=sum/2;
            sum++;
        }
        int count=0;
        while(true)
        {
            if(nums1[i]>=nums2[j])
            {
                ans=nums1[i];
                count++;
                if(!check && count==sum) //even so 2 digits taking
                {
                    if(i!=m-1 && nums1[i]>=nums2[j])
                    {
                        ans+=nums1[i];
                    }
                    else
                    {
                        ans+=nums2[j];
                    }
                    return ans/2;
                }
                else if(check && count==sum)
                {
                    return ans;
                }
                if(i!=m-1) i++;
            }
            else if(nums1[i]<=nums2[j])
            {
                ans=nums2[j];
                count++;
                if(!check && count==sum)
                {
                    if(j!=n-1 && nums2[j]>=nums1[i])
                    {
                        ans+=nums2[j];
                    }
                    else
                    {
                        ans+=nums1[i];
                    }
                    return ans/2;
                }
                else if(check && count==sum)
                {
                    return ans;
                }
                if(j!=n-1) j++;
            }
        }
        return -1;
    }
};