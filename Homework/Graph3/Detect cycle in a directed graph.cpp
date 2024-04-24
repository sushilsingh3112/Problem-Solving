class Solution {
private:
    bool Checkdfs(int src, unordered_map<int,bool>& visited, unordered_map<int,bool>& dfsvisited, vector<int> adj[]) {
        visited[src] = true;
        dfsvisited[src] = true;
        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                bool boolAns = Checkdfs(nbr, visited, dfsvisited, adj);
                if (boolAns)
                    return true;
            }
            else if (dfsvisited[nbr])
                return true;
        }
        dfsvisited[src] = false; // Reset the dfsvisited flag after exploration
        return false;
    }
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsvisited;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                int src = i;
                if (Checkdfs(src, visited, dfsvisited, adj))
                    return true;
            }
        }
        return false;
    }
};
