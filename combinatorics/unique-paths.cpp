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
        int uniquePaths(int m, int n) 
        {
            vector<int> prev(n+1,0);
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++)
            {
                prev[j]=1;
            }
            for(int i=2;i<=m;i++)
            {
                curr[1]=1;
                for(int j=2;j<=n;j++)
                {
                    curr[j]=prev[j] + curr[j-1];
                }
                prev=curr;   
            }
            return prev[n];
        }
};