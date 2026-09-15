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
        if(matrix.size()==0 || matrix[0].size()==0) return;
        int row=matrix.size();
        int col=row>0 ? matrix[0].size() : 0;
        temp=vector<vector<int>>(row+1,vector<int>(col+1,0));
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                temp[i][j]=matrix[i-1][j-1]+
                        temp[i-1][j]+temp[i][j-1]-temp[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return temp[row2+1][col2+1]-temp[row2+1][col1]-temp[row1][col2+1]+temp[row1][col1];
    }
};