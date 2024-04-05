int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  vector<int> matrix1d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix1d.push_back(mat[i][j]);
        }
    }

    sort(matrix1d.begin(), matrix1d.end());

    for (int i = 0; i < (n * n); i++) {
        if (i == k - 1) {
            return matrix1d[i];
        }
    }
    return -1;
}
