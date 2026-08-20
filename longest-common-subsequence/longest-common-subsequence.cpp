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
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();

        vector<int> prev(n + 1,0),cur(n+1,0);
        //shifted 1 index
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    //check the -1 index as we shifted earlier
                    cur[j]=1+prev[j-1];
                }
                else
                {
                    cur[j]=max(prev[j],cur[j-1]);
                }
            }
            prev=cur;
        }
        return prev[n];
    }
};