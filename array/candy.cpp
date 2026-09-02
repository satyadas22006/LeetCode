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
    int candy(vector<int>& ratings) 
    {
        //give 1 to each then 
        //int hmm=0;
        int n=ratings.size();
        vector<int> hmm(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i-1]<ratings[i])
            {
                hmm[i]=hmm[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i+1]<ratings[i])
            {
                hmm[i]=hmm[i+1]+1;
            }
        }
        int sum=0;
        for(auto i:hmm)
        {
            sum+=i;
        }
        return sum;
    }
};