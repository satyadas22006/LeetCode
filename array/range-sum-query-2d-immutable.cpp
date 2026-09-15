#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> temp;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        temp=matrix;
    }   
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int ans=0;
        for(int i=row1;i<=row2;i++)
        {
            for(int j=col1;j<=col2;j++)
            {
                ans+=temp[i][j];
            }
        }
        return ans;
    }
};