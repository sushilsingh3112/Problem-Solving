int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>>grid(A+1,vector<int>(B+1));
    vector<vector<bool>>visited(A+1,vector<bool>(B+1,false));
    queue<pair<int,pair<int,int>>>q;
     visited[C][D] = true;

    q.push({0,{C,D}});
    int cnt = 0;
    
    while(!q.empty()){
        int dist = q.front().first;
        int ci = q.front().second.first;
        int cj = q.front().second.second;

        if(ci == E and cj==F){
            return dist;
        }
        q.pop();
        
        int di[] = {-2,-2,2,2,-1,1,-1,1};
        int dj[] = {-1,1,-1,1,2,2,-2,-2};
        
        for(int k=0;k<8;k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];
            
            if(ni>=1 && nj>=1 && ni<=A && nj<=B && !visited[ni][nj]){
                visited[ni][nj] = true;
                q.push({dist + 1,{ni,nj}});

            }

        }

    }

    return -1;
}
