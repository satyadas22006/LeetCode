class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();

        vector<long long> prev(amount + 1, 0);
        vector<long long> curr(amount + 1, 0);

        // Base case: only coins[0]
        for(int a = 0; a <= amount; a++)
        {
            if(a % coins[0] == 0)
            {
                prev[a] = 1;
            }
        }

        for(int ind = 1; ind < n; ind++)
        {
            for(int a = 0; a <= amount; a++)
            {
                long long nottake = prev[a];

                long long take = 0;

                if(coins[ind] <= a)
                {
                    take = curr[a - coins[ind]];
                }

                curr[a] = take + nottake;
            }

            prev = curr;
        }

        return prev[amount];
    }
};