class Solution 
{
public:
    vector<int> parent,rank;

    int find(int x)
    {
        if(parent[x]==x)
            return x;

        return parent[x]=find(parent[x]);
    }

    bool unite(int u,int v)
    {
        int pu=find(u);
        int pv=find(v);

        if(pu==pv)
            return false;

        if(rank[pu]<rank[pv])
            parent[pu]=pv;
        else if(rank[pu]>rank[pv])
            parent[pv]=pu;
        else
        {
            parent[pu]=pv;
            rank[pv]++;
        }

        return true;
    }

    int cost_mst(int n, vector<int>& skip,
                 vector<vector<int>>& edges,
                 unordered_map<int,int>& appear)
    {
        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;

        int cost=0;
        int count=0;

        for(auto &e:edges)
        {
            if(e==skip)
                continue;

            int x=e[0];
            int y=e[1];
            int w=e[2];

            if(find(x)!=find(y))
            {
                unite(x,y);

                // keep your appear map
                appear[e[3]]++;

                cost+=w;
                count++;

                if(count==n-1)
                    break;
            }
        }

        if(count!=n-1)
            return INT_MAX;

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges) 
    {
        // original index
        for(int i=0;i<edges.size();i++)
            edges[i].push_back(i);

        sort(edges.begin(),edges.end(),
            [](vector<int>& a,vector<int>& b)
            {
                return a[2]<b[2];
            });

        vector<vector<int>> ans(2);

        unordered_map<int,int> appear;
        vector<int> temp={-1,-1,-1,-1};
        int min_cost=cost_mst(n,temp,edges,appear);

        for(auto &e:edges)
        {
            // reset appear for this MST
            appear.clear();

            int newcost=cost_mst(n,e,edges,appear);

            if(newcost>min_cost)
            {
                ans[0].push_back(e[3]);
                continue;
            }

            // Check whether this edge appears in an MST
            if(newcost==min_cost)
            {
                // e was skipped, so we need to force it
                parent.resize(n);
                rank.assign(n,0);

                for(int i=0;i<n;i++)
                    parent[i]=i;

                int cost=e[2];
                int count=1;

                unite(e[0],e[1]);

                appear.clear();
                appear[e[3]]++;

                for(auto &x:edges)
                {
                    if(x==e)
                        continue;

                    if(unite(x[0],x[1]))
                    {
                        cost+=x[2];
                        count++;
                        appear[x[3]]++;

                        if(count==n-1)
                            break;
                    }
                }

                if(cost==min_cost)
                {
                    ans[1].push_back(e[3]);
                }
            }
        }

        return ans;
    }
};