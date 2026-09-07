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
            unordered_map<int,int> mp;
            int m=0;
            for(int i:nums)
            {
                mp[i]++;
                m=max(m,i);
            }
            for(int i=1;i<=m;i++)
            {
                if(!mp[i]) return i;
            }
            return m+1;            
        }
};