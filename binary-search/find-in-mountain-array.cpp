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
        int findInMountainArray(int target, MountainArray &mountainArr) 
        {
            //find the peak first by binary search
            int l=1;
            int n=mountainArr.length();
            int r=n-1;
            int mid=l+(r-l)/2;
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if(mountainArr.get(mid-1)<mountainArr.get(mid))
                {
                    //lies on left side of slope
                    l=mid+1;
                }
                else if(mountainArr.get(mid-1)>mountainArr.get(mid))
                {
                    //lies on right side of slope
                    r=mid-1;
                }
                else
                {
                    if(mountainArr.get(mid)>mountainArr.get(mid+1) && mountainArr.get(mid)>mountainArr.get(mid-1))
                    {
                        break;
                    }
                }
            }
            //mid at last is the peak index
            //now find the element in left side and right side both
            l=0;
            r=mid;
            mid=l+(r-l)/2;
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if(mountainArr.get(mid)<target)
                {
                    l=mid+1;
                }
                else if(mountainArr.get(mid)>target)
                {
                    r=mid-1;
                }
                else if(mountainArr.get(mid)==target)
                {
                    return mid;
                }
            }
            //right side search
            l=mid;
            r=n-1;
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if(mountainArr.get(mid)>target)
                {
                    l=mid+1;
                }
                else if(mountainArr.get(mid)<target)
                {
                    r=mid-1;
                }
                else if(mountainArr.get(mid)==target)
                {
                    return mid;
                }
            }
            return -1;
        }
};