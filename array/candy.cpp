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
        for(int i=0;i<n;i++)
        {
            //check if back or front is higher
            //back higher
            if(i-1>=0 && ratings[i-1]<ratings[i])
            {
                //bigger than back then increase if equal or less
                if(hmm[i-1]>=hmm[i])
                {
                    hmm[i]=hmm[i-1]+1;
                }
            }
            if(i+1<n && ratings[i+1]<ratings[i])
            {
                if(hmm[i+1]>=hmm[i])
                {
                    hmm[i]=hmm[i+1]+1;
                }
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