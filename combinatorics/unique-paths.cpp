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
            //prev and 
            vector<int> prev(m+1) , curr(m+1); // row ka size 
            for(int i=1;i<=m;i++)
            {
                prev[i]=1; // all cells set to 1
            }
            for(int i=2;i<=n;i++)
            {
                curr[1]=1;
                for(int j=2;j<=m;j++)
                {
                    curr[j]=prev[j] + curr[j-1];
                }
                prev=curr;
            }

            return prev[m];
        }
};