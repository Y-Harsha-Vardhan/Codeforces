#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solveCase(int n, const vector<int>& a) {
    vector<ll> dp(n + 1, LLONG_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        int p = i + 1;
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] < a[p]) {
                p = j;
            }
        }
        for (int j = p; j <= n; ++j) {
            ll swapCost     = 2LL * (j - p);
            ll overtakeCost = 1LL * (j - i) * a[p];
            ll backtrack    = p - i - 1;
            dp[i] = min(dp[i], dp[j] + swapCost + overtakeCost + backtrack);
        }
    }
    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cout << solveCase(n, a) << "\n";
    }

    return 0;
}
