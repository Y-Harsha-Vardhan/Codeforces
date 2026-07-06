#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    int arr[n+1];
    vector<int> cnt(30, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        for (int j = 0; j < 30; j++) {
            cnt[j] += ((arr[i] >> j) & 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tot = 0;
        for (int j = 0; j < 30; j++) {
            bool f = ((arr[i] >> j) & 1);
            if (f) tot += (1 << j) * (n - cnt[j]);
            else tot += (1 << j) * cnt[j];
        }
        ans = max(ans, tot);
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}