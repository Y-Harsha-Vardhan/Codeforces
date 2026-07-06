#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int compute_log_ceiling(int value) {
    if (value <= 0) return INT_MAX;
    if (value == 1) return 0;
    return 32 - __builtin_clz(value - 1);
}

void solve_test_case() {
    int numRows, numCols, cutRow, cutCol;
    cin >> numRows >> numCols >> cutRow >> cutCol;

    int logRowsOriginal = compute_log_ceiling(numRows);
    int logColsOriginal = compute_log_ceiling(numCols);

    int rowsAfterCut = min(cutRow, numRows - cutRow + 1);
    int costRowCut = 1 + compute_log_ceiling(rowsAfterCut) + logColsOriginal;

    int colsAfterCut = min(cutCol, numCols - cutCol + 1);
    int costColCut = 1 + logRowsOriginal + compute_log_ceiling(colsAfterCut);

    int minCost = min(costRowCut, costColCut);
    cout << minCost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve_test_case();
    }

    return 0;
}