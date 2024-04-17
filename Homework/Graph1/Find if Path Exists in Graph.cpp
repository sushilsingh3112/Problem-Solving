class Solution {
public:
bool check(unordered_map<int,vector<int>> &adjlist,int S,int D,vector<bool>&visited){

    if(S==D)
    return true;

    if(visited[S]==true)
    return false;
    visited[S]=true;
    for(auto &node:adjlist[S]){
        if(check(adjlist,node,D,visited)==true)
        return true;
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>>adjlist;
        for(vector<int>&edge:edges){
            int u=edge[0];
            int v=edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<bool>visited(n,false);
        return check(adjlist,source,destination,visited);
    }
};
