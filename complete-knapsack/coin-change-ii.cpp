class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<long long> dp(amount + 1, 0);

        dp[0] = 1;

        for(int ind = 0; ind < coins.size(); ind++)
        {
            for(int a = coins[ind]; a <= amount; a++)
            {
                dp[a] += dp[a - coins[ind]];
            }
        }

        return dp[amount];
    }
};