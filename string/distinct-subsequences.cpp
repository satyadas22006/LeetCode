class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Empty t can always be formed in exactly 1 way
        for(int i = 0; i <= m; i++)
        {
            dp[i][n] = 1;
        }

        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                int not_take = dp[i + 1][j];
                int take = 0;

                if(s[i] == t[j])
                {
                    take = dp[i + 1][j + 1];
                }

                if(take > INT_MAX - not_take)
                {
                    dp[i][j] = INT_MAX;
                }
                else
                {
                    dp[i][j] = take + not_take;
                }
            }
        }

        return dp[0][0];
    }
};