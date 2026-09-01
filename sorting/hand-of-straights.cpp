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
        if(hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        unordered_map<int,int> mp;

        for(int x : hand)
            mp[x]++;

        for(int x : hand)
        {
            //
            if(mp[x]==0)
                continue;
            for(int j=0;j<groupSize;j++)
            {
                //find all its consecutive
                if(mp[x+j]==0)
                {
                    //means x is alone solo, nobody from behind x took it and theres noone after x
                    return false;
                }
                mp[x+j]--;
            }
        }

        return true;
    }
};