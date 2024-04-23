class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>indgree(n,false);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            indgree[v]=true;

        }
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indgree[i]==false){
            ans.push_back(i);
        }
        }
        return ans;
    }
};
