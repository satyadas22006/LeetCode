class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]!='0' || s[0]!='0') return false;
        int l = 0;
        int r = 0;

        while (l <= r) {

            int newL = r + 1;
            int newR = r;

            for (int i = l; i <= r; i++) {

                if (s[i] == '0') {
                    newL = min(newL, i + minJump);
                    newR = max(newR, i + maxJump);
                }
            }

            // Keep only valid indices
            newL = max(newL, 0);
            newR = min(newR, n - 1);

            if (newL > newR)
                return false;

            if (newR == n - 1)
                return true;

            l = newL;
            r = newR;
        }

        return false;
    }
};