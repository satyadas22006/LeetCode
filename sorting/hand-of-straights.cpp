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
        bool isNStraightHand(vector<int>& hand, int groupSize) 
        {
            if(hand.size()%groupSize!=0)
            {
                return false;
            }
            sort(hand.begin(),hand.end());
            vector<unordered_map<int,int>> groups(groupSize);
            for(int i:hand)
            {
                int k=0;
                while(groups[k][i]>0 || groups[k].size()==groupSize)
                {
                    k++;
                    if(k>=groupSize)
                    {
                        return false;
                    }
                }
                groups[k][i]++;
                break;
            }
            return true;
        }
};