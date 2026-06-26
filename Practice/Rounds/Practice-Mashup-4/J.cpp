#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n; ll X; cin >> n >> X;
        vector<ll> a(n); ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        } sort(a.begin(), a.end());
        ll k = sum / X; ll ans = 0;
        for (int i = n - k; i < n; i++) ans += a[i];
        cout << ans << '\n';

        int l = 0, r = n - 1; ll cur = 0;
        vector<ll> order; order.reserve(n);
        while (l <= r) {
            if (cur + a[r] >= X) {
                order.push_back(a[r]);
                cur = (cur + a[r]) % X;
                --r;
            } else {
                order.push_back(a[l]);
                cur = (cur + a[l]) % X;
                ++l;
            }
        }

        for (int i = 0; i < n; i++) cout << order[i] << " ";
        cout << "\n";
    }
}