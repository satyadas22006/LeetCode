class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, 
                          int src, int dst, int k) 
    {
        // adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(auto x : flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }

        // {cost, {destination, flightsTaken}}
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        pq.push({0, {src, 0}});

        while(!pq.empty())
        {
            auto [cost, info] = pq.top();
            pq.pop();

            int stops = info.second;
            int dest = info.first;

            if(dest == dst)
            {
                return cost;
            }

            if(stops == k + 1)
            {
                continue;
            }

            // only check flights leaving current city
            for(auto x : adj[dest])
            {
                int next = x.first;
                int price = x.second;

                int temp = cost + price;

                pq.push({
                    temp,
                    {next, stops + 1}
                });
            }
        }

        return -1;
    }
};