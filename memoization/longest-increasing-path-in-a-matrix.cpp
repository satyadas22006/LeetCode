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

class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& matrix)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int start=matrix[i][j];
        int ans=1;
        int res=1;
        for(int k=0;k<4;k++)
        {
            int ni=i+x[k];
            int nj=j+y[k];
            if(ni>=matrix.size() || nj>=matrix[0].size() || ni<0 || nj<0)
            {
                continue;
            }
            if(matrix[ni][nj]>start)
            {
                res=1+f(ni,nj,dp,matrix);
                ans=max(res,ans);
            }
        }   
        return dp[i][j]=ans;     
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int res=f(i,j,dp,matrix);
                ans=max(res,ans);
            }
        }
        return ans;
    }
};