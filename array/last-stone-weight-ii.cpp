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
        int lastStoneWeightII(vector<int>& stones) 
        {
            //sort(stones.begin(),stones.end());
            int s=0;
            for(int i:stones)
            {
                s+=i;
            }
            int n=stones.size();
            int target=s/2;
            vector<vector<int>> dp(n,vector<int>(target+1,0));
            for(int i=0;i<n;i++)
            {
                //when target is 0, return 0
                dp[i][0]=0;
            }
            for(int j=stones[0];j<=target;j++)
            {
                dp[0][j]=stones[0];
            }
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<=target;j++)
                {
                    int not_take=dp[i-1][j];
                    int take=INT_MIN;
                    if(stones[i]<=j)
                    {
                        take=stones[i] + dp[i-1][j-stones[i]];
                    }
                    dp[i][j]=max(take,not_take);
                }
            }
            return s-2*dp[n-1][target];
            //return s-2*f(target,0,stones,dp);
        }
};