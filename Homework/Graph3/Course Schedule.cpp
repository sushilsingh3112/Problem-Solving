class Solution {
public:
bool topologicalSortCheck(unordered_map<int,vector<int>>&adj,int n,vector<int>indgree){
 queue<int>q;
 int count=0;
 for(int i=0;i<n;i++){
    if(indgree[i]==0){
        count++;
        q.push(i);
    }
  }
    while(!q.empty()){
     int u=q.front();
     q.pop();
     for(int &v:adj[u]){
        indgree[v]--;
        if(indgree[v]==0){
            count++;
            q.push(v);
        }
     }
    }
    if(count==n)
        return true;
        return false;
}
 

    bool canFinish(int numCourse, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indgree(numCourse,0);
        for(auto&vec:prerequisites){
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
            indgree[a]++;
        }
        return topologicalSortCheck(adj,numCourse,indgree);
    }
};
