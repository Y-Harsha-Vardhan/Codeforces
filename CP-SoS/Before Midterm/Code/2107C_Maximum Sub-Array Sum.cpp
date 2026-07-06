#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, ll k, string s, vector<ll> a) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            pos = i;
            a[i] = -1e13;
        }
    }

    ll mx = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        curr = max(curr + a[i], a[i]);
        mx = max(mx, curr);
    }

    if (mx > k || (mx != k && pos == -1)) {
        cout << "No\n";
        return;
    }

    if (pos != -1) {
        mx = 0, curr = 0;
        ll L = 0, R = 0;

        for (int i = pos + 1; i < n; i++) {
            curr += a[i];
            mx = max(mx, curr);
        }
        L = mx;

        mx = 0, curr = 0;
        for (int i = pos - 1; i >= 0; i--) {
            curr += a[i];
            mx = max(mx, curr);
        }
        R = mx;

        a[pos] = k - L - R;
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i + 1 == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        string s; cin >> s;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;
        solve(n, k, s, a);
    }
    return 0;
}
