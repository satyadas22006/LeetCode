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
        string simplifyPath(string path) 
        {
            stack<string> s;
            string ans;
            if(path[0]=='/') ans.push_back(path[0]);
            for(int i=1;i<path.size();i++)
            {
                if(((i+1<path.size() && path[i+1]=='/') || i==path.size()-1) &&  path[i]=='.' )
                {
                    // /./ curr directory
                    //current directory toh skip it for now
                    i++;
                    //reached i+2 now
                    continue;
                }
                if(((i+2<path.size()&& path[i+2]=='/') || i+2==path.size()-1) && path[i]=='.' && path[i+1]=='.')
                {
                    // /../ prev directory ko remove from stack
                    if(!s.empty()) s.pop();
                    i++;
                    i++;
                    //reached i+3 now
                    continue;
                }
                if(path[i]=='/')
                {
                    while(path[i]=='/') i++;
                    i--;
                    continue;
                }
                string temp="";
                while(i<path.size() && path[i]!='/')
                {
                    temp.push_back(path[i]);
                    i++;
                }
                s.push(temp);
            }
            stack<string> fnl;
            while(!s.empty())
            {
                fnl.push(s.top());
                s.pop();
            }
            while(!fnl.empty())
            {
                auto p=fnl.top();
                fnl.pop();
                for(auto k:p) ans.push_back(k);
                if(!fnl.empty()) ans.push_back('/');
            }
            return ans;
        }
};