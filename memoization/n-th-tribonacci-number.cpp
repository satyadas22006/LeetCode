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
        int tribonacci(int n) 
        {
            if(n<=2)
            {
                if(n==0)
                {
                    return 0;
                }
                return 1;
            }
            vector<int> fib(n+1,0);
            fib[0]=0;
            fib[1]=1;
            fib[2]=1;
            for(int i=3;i<=n;i++)
            {
                //3rd element
                fib[i]=fib[i-1]+fib[i-2]+fib[i-3];
            }
            return fib[n];
        }
};