class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;

        // Adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min heap: {distance, node}
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                // Shorter path found
                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                // Another shortest path
                else if (d + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[V - 1] % MOD;
    }
};
