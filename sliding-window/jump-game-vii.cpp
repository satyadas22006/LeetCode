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
        bool f(int i,int minJump,int maxJump,string s)
        {
            if(i>=s.size()-1)
            {
                return true;
            }
            int l=i+minJump;
            int r=i+maxJump;
            bool check=false;
            for(int i=l;i<=r;i++)
            {
                if(s[i]=='0')
                {
                    check=true;
                    bool res=f(i,minJump,maxJump,s);
                    if(res==true)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool canReach(string s, int minJump, int maxJump) 
        {
            if(s[0]!='0')
            {
                return false;
            }
            //starts with 0 fs
            return f(0,minJump,maxJump,s);
        }
};