class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int t = 0; t < n; t++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][j] > dist[i][t] + dist[t][j]){
                        dist[i][j] = dist[i][t] + dist[t][j];
                    }
                }
            }
        }
        int mincnt = n, city = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(mincnt >= cnt){
                mincnt = cnt;
                city = i;
            }
        }
        return city;
    }
};
