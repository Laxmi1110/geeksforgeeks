class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        
        // Convert edges into single outgoing representation
        for (auto &e : edges) {
            adj[e[0]] = e[1];
        }
        
        vector<int> visited(V, 0);
        vector<int> time(V, 0);
        
        int ans = -1;
        
        for (int i = 0; i < V; i++) {
            if (visited[i]) continue;
            
            int node = i;
            int step = 0;
            
            unordered_map<int, int> mp; // stores node -> step
            
            while (node != -1 && !visited[node]) {
                visited[node] = 1;
                mp[node] = step++;
                node = adj[node];
                
                if (node != -1 && mp.count(node)) {
                    // Cycle found
                    ans = max(ans, step - mp[node]);
                    break;
                }
            }
        }
        
        return ans;
    }
};
