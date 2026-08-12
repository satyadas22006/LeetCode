class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, 
                          int src, int dst, int k) 
    {
        // adj[u] = {v, cost}
        vector<vector<pair<int,int>>> adj(n);

        for(auto x : flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }

        // {cost, {city, flightsTaken}}
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        // dist[city][flightsTaken]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;

        pq.push({0, {src, 0}});

        while(!pq.empty())
        {
            auto [cost, info] = pq.top();
            pq.pop();

            int city = info.first;
            int flightsTaken = info.second;

            if(city == dst)
                return cost;

            if(flightsTaken == k + 1)
                continue;

            // Outdated state
            if(cost > dist[city][flightsTaken])
                continue;

            for(auto [next, price] : adj[city])
            {
                int newCost = cost + price;
                int newFlights = flightsTaken + 1;

                if(newCost < dist[next][newFlights])
                {
                    dist[next][newFlights] = newCost;

                    pq.push({
                        newCost,
                        {next, newFlights}
                    });
                }
            }
        }

        return -1;
    }
};