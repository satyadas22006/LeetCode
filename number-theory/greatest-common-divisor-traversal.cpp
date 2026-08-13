#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <math.h>
using namespace std;


class Solution 
{
    public:
        vector<int> parent;
        vector<int> rank;
        int find(int x)
        {
            if(parent[x]==x)
            {
                return x;
            }
            return parent[x]=find(parent[x]);
        }
        bool unite(int u,int v)
        {
            int pu=find(u);
            int pv=find(v);

            if(pu==pv)
            {
                //already same parent exists
                return false;
            }

            if(rank[pu]<rank[pv])
            {
                parent[pu]=pv;
            }
            else if(rank[pu]>rank[pv])
            {
                parent[pv]=pu;
            }
            else
            {
                parent[pu]=pv;
                rank[pv]++;
            }

            return true;

        }
        int gcd(int a,int b)
        {
            int ans=1;
            for(int i=1;i<=min(a,b);i++)
            {
                if(a%i==0 && b%i==0)
                {
                    ans=i;
                }
            }
            return ans;
        }
        bool canTraverseAllPairs(vector<int>& nums) 
        {
            //build dsu
            int n=nums.size();
            parent.resize(n);
            rank.assign(n,0);
            for(int i=0;i<n;i++)
            {
                parent[i]=i; //parents find krdiya sabka
            }

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(gcd(nums[i],nums[j]) > 1)
                    {
                        unite(i,j);
                    }
                }
            }

            int p=find(0);

            for(int i=1;i<n;i++)
            {
                if(find(i)!=p)
                {
                    return false;
                }
            }
            return true;
        }
};