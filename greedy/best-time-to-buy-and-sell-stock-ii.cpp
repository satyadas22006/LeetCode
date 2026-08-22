#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;


class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            //local minima

            int b=0;
            while(b<prices.size()-1)
            {
                if(prices[b+1]<=prices[b])
                {
                    b++;
                }
                else
                {
                    break;
                }
            }
            int s=b+1;
            int profit=0;
            bool hold=true;
            for(int s=b+1;s<prices.size()-1;s++)
            {
                hold=false;
                if(prices[s]>prices[s-1] && prices[s]>=prices[s+1])
                {
                    profit+=prices[s]-prices[b];
                    //sold
                    b=s+1;
                    while(b<prices.size()-1)
                    {
                        if(prices[b+1]<=prices[b])
                        {
                            b++;
                            
                        }
                        else
                        {
                            break;
                        }
                    }
                    s=b;
                    
                }
                if(s+1==prices.size()-1)
                {
                    profit+=prices[s+1]-prices[b];
                    s++;
                }
            }
            if(hold && s<prices.size())
            {
                if(prices[s]>prices[b])
                {
                    profit+=prices[s]-prices[b];
                }
            }
            return profit;
        }
};