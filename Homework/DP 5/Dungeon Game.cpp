/*class Solution {
    public:
Approach 1 Using recursion 
    int calculateMinimumHealth(vector<vector<int>>& dungeon, int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) {
           return max(1, 1 - dungeon[i][j]);
        }
        if (i >= m || j >= n) {
            return INT_MAX;
        }
        int healthOnEnter = min(calculateMinimumHealth(dungeon, i + 1, j, m, n),
                                calculateMinimumHealth(dungeon, i, j + 1, m, n)) - dungeon[i][j];
        return max(1, healthOnEnter);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        return calculateMinimumHealth(dungeon, 0, 0, m, n);
    }
    
};*/

Approach 2 rec+memo
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty())
            return 0;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
        for (int i = m - 2; i >= 0; i--){
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }
        for (int j = n - 2; j >= 0; j--){
            dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int right = max(1, dp[i][j + 1] - dungeon[i][j]);
                int down = max(1, dp[i + 1][j] - dungeon[i][j]);
                dp[i][j] = min(right, down);
            }
        }
        return dp[0][0];
    }

};
