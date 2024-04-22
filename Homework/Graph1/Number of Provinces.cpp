class Solution {
private:
    unordered_map<int, bool> visited;

    void dfs(int src, vector<vector<int>>& isConnected) {
        visited[src] = true;
        int size = isConnected[src].size();
        for (int col = 0; col < size; col++) {
            if (src != col && isConnected[src][col] == 1) {
                if (!visited[col]) {
                    dfs(col, isConnected);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        visited.clear(); // Clear visited map for each test case
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected);
                count++;
            }
        }
        return count;
    }
};
