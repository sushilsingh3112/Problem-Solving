#include <bits/stdc++.h>
using namespace std;
int countpainters(vector<int> &boards, int time) {
    int n = boards.size();
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            boardsPainter += boards[i];
        }
        else {
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k) {
    int i= *max_element(boards.begin(), boards.end());
    int j = accumulate(boards.begin(), boards.end(), 0);
    while (i <= j) {
        int mid = (i + j) / 2;
        int painters = countpainters(boards, mid);
        if (painters > k) {
            i = mid + 1;
        }
        else {
            j = mid - 1;
        }
    }
    return i;
}
