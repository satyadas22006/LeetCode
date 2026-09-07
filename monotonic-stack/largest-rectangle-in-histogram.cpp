#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;

class Solution 
{
    public:
        int largestRectangleArea(vector<int>& heights) 
        {
            //go left and go right
            vector<int> left(heights.size(),0);
            vector<int> right(heights.size(),0);
            stack<int> s;
            for(int i=0;i<heights.size();i++)
            {
                //int count=0;
                while(!s.empty() && heights[i]<=heights[s.top()])
                {
                    s.pop();
                }
                left[i]=s.empty()? -1 : s.top();
                s.push(i);
            }
            while(!s.empty()) s.pop();

            for(int i=heights.size()-1;i>=0;i--)
            {
                while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
                right[i]=s.empty()? heights.size() : s.top();
                s.push(i);
            }
            int ans=0;
            for(int i=0;i<heights.size();i++)
            {
                int width=right[i]-left[i]-1;
                ans=max(ans,heights[i]*width);
            }
            return ans;
        }
};