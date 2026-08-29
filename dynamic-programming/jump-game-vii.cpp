class Solution 
{
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n = s.size();

        if(s[0] != '0' || s[n - 1] != '0')
            return false;

        int r = 0;

        for(int i = 0; i < n; i++)
        {
            if(i > r || s[i] != '0')
                continue;

            int nl = i + minJump;
            int nr = min(i + maxJump, n - 1);

            for(int j = max(nl, r + 1); j <= nr; j++)
            {
                if(s[j] == '0')
                {
                    if(j == n - 1)
                        return true;

                    s[j] = '2';
                }
            }

            r = max(r, nr);
        }

        return n == 1;
    }
};