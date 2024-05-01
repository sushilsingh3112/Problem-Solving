class Solution{
public:
    int minimumEdgeReversal(vector<vector<int>>& edges, int n, int src, int dst) {
        unordered_map<int, vector<pair<int, int>>> adj; 
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 0}); 
            adj[v].push_back({u, 1}); 
        }     
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> s;
        s.insert({0, src});
        dist[src] = 0;
        while (!s.empty()) {
            auto topElement = s.begin();
            int topDist = topElement->first;
            int topNode = topElement->second;
            s.erase(topElement);
            
            for (auto& nbrPair : adj[topNode]) {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                
                if (topDist + nbrDist < dist[nbrNode]) {
                    auto pairSourceEntry = s.find({dist[nbrNode], nbrNode});
                    if (pairSourceEntry != s.end()) {
                        s.erase(pairSourceEntry);
                    }
                    dist[nbrNode] = topDist + nbrDist;
                    s.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        
        if (dist[dst] != INT_MAX) {
            return dist[dst];
        }
        
        return -1; 
    }
};
