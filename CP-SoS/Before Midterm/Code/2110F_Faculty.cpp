#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x, ll y) {
    return (x % y) + (y % x);
}

void solve(vector<ll> a) {
    int n = a.size();
    ll ans = 0;
    ll mx = a[0];

    for (int i = 0; i < n; ++i) {
        ans = max(ans, f(mx, a[i]));

        if (a[i] > mx) {
            if (a[i] >= 2 * mx) {
                mx = a[i];
                for (int j = 0; j < i; ++j) {
                    ans = max(ans, f(a[i], a[j]));
                }
            } else {
                mx = a[i];
                ans = mx;
            }
        }

        cout << ans << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll& x : a) cin >> x;
        solve(a);
    }
}
