class Solution 
{
public:
    bool checkValidString(string s) 
    {
        int n = s.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, 0)
        );

        // Base case:
        // i == n
        // valid only when number of open brackets = 0
        dp[n][0] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= n; j++)
            {
                // j = number of unmatched '('

                bool check = false;

                if(s[i] == '(')
                {
                    if(j + 1 <= n)
                        check = dp[i + 1][j + 1];
                }

                else if(s[i] == ')')
                {
                    if(j > 0)
                        check = dp[i + 1][j - 1];
                }

                else // '*'
                {
                    // take '*' as '('
                    if(j + 1 <= n)
                        check = check || dp[i + 1][j + 1];

                    // take '*' as ')'
                    if(j > 0)
                        check = check || dp[i + 1][j - 1];

                    // take '*' as nothing
                    check = check || dp[i + 1][j];
                }

                dp[i][j] = check;
            }
        }

        return dp[0][0];
    }
};