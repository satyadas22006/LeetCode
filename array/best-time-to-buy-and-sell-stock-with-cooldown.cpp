#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <math.h>
using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            int n=prices.size();
            vector<int> s0(n,0);
            vector<int> s1(n,0);
            vector<int> s2(n,0);
            s0[0]=0;
            s1[0]=-prices[0];
            s2[0]=INT_MIN;

            for(int i=1;i<n;i++)
            {
                s0[i]=max(s0[i-1],s2[i-1]);
                s1[i]=max(s1[i-1],-prices[i]+s0[i-1]);
                s2[i]=prices[i]+s1[i-1];
            }

            return max(s0[n-1],s2[n-1]);
        }
};