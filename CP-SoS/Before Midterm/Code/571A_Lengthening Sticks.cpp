#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count_invalid(int x, int y, int z, int l) {
    ll res = 0;
    for (int i = 0; i <= l; ++i) {
        int A = x + i;
        int rem = l - i;
        int limit = A - y - z;
        if (limit < 0) continue;
        ll t = min(rem, limit);
        res += (t + 1) * (t + 2) / 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, l;
    cin >> a >> b >> c >> l;

    ll total = (ll)(l + 3) * (l + 2) * (l + 1) / 6;

    ll bad = count_invalid(a, b, c, l);
    bad += count_invalid(b, c, a, l);
    bad += count_invalid(c, a, b, l);

    cout << (total - bad) << '\n';
    return 0;
}