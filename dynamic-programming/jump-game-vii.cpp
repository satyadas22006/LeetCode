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
        bool canReach(string s, int minJump, int maxJump) 
        {
            if(s[0]!='0' || s[s.size()-1]!='0')
            {
                return false;
            }
            queue<int> q;
            q.push(0);
            int r=INT_MIN;
            while(!q.empty())
            {
                int i=q.front();
                q.pop();
                int nl=i+minJump;
                int nr=i+maxJump;
                if(nl>=(int)s.size())
                {
                    continue;
                }
                nr=min(nr,(int)s.size()-1);
                if(nr<=r)
                {
                    continue;
                }
                for(int j=nl;j<=nr;j++)
                {
                    if(s[j]=='0')
                    {
                        if(j==s.size()-1)
                        {
                            return true;
                        }
                        q.push(j);
                    }
                }
                r=max(r,nr);
            }
            return false;
        }
};