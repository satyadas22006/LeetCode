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
            if(mp[x] == 0)
                continue;

            for(int j = 0; j < groupSize; j++)
            {
                if(mp[x + j] == 0)
                    return false;

                mp[x + j]--;
            }
        }

        return true;
    }
};