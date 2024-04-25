class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int dirRow[] = {-1, 0, 1, 0};
        int dirCol[] = {0, 1, 0, -1};
        int time = 0;

        // Loop through the grid to find initially rotten oranges and add them to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); // Push the position of the rotten orange and time 0
                }
            }
        }

        // Perform BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            // Check the neighbors of the current orange
            for (int i = 0; i < 4; i++) {
                int NRow = r + dirRow[i];
                int NCol = c + dirCol[i];

                // Check if the neighbor is within the grid and is a fresh orange
                if (NRow >= 0 && NRow < n && NCol >= 0 && NCol < m && grid[NRow][NCol] == 1) {
                    // Mark the neighbor as rotten and push it to the queue with updated time
                    grid[NRow][NCol] = 2;
                    q.push({{NRow, NCol}, t + 1});
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1; // If there are fresh oranges left, return -1
                }
            }
        }

        return time; // Return the time taken for all oranges to rot
    }

    
};
