class Solution {
public:
    bool isbipartite(int src,unordered_map<int,vector<int>> &adj,vector<int> &color){
        queue<int>q;
        q.push(src);
        color[src]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nbr:adj[node]){
                if(color[nbr]==-1){
                    color[nbr]=!color[node];
                    q.push(nbr);
                }
                else if(color[node]==color[nbr]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<graph.size();i++){
            for(auto nbr:graph[i]){
                adj[i].push_back(nbr);
                adj[nbr].push_back(i);
            }
        }
        vector<int> color(graph.size(),-1);
        bool ans=false;
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                 ans=isbipartite(i,adj,color);
                if(ans==false) return false;
            }
        }
        
        return true;;
    }
};
