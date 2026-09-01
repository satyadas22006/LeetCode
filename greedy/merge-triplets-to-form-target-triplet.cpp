#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
class Solution 
{
    public:
        bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
        {
            bool flag1=false;
            bool flag2=false;
            bool flag3=false;
            for(int i=0;i<triplets.size();i++)
            {
                if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2])
                {
                    if(triplets[i][0]==target[0]) flag1=true;
                    if(triplets[i][1]==target[1]) flag2=true;
                    if(triplets[i][2]==target[2]) flag3=true;
                }
            }
            return (flag1&&flag2&&flag3);          
        }
};