#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;
ll mn[4*MAXN], lazyv[4*MAXN];

void apply(int idx, ll val) {
    mn[idx] += val;
    lazyv[idx] += val;
}

void push(int idx, int l, int r) {
    if (lazyv[idx] != 0 && l != r) {
        apply(idx<<1, lazyv[idx]);
        apply(idx<<1|1, lazyv[idx]);
        lazyv[idx] = 0;
    }
}

void update(int idx, int l, int r, int ql, int qr, ll val) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        apply(idx, val);
        return;
    }
    push(idx, l, r);
    int m = (l + r) >> 1;
    update(idx<<1, l, m, ql, qr, val);
    update(idx<<1|1, m+1, r, ql, qr, val);
    mn[idx] = min(mn[idx<<1], mn[idx<<1|1]);
}

ll query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return LLONG_MAX;
    if (ql <= l && r <= qr) return mn[idx];
    push(idx, l, r);
    int m = (l + r) >> 1;
    return min(query(idx<<1, l, m, ql, qr),
               query(idx<<1|1, m+1, r, ql, qr));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        update(1, 1, n, i, i, x);
    }

    int m;
    cin >> m;
    while(m--) {
        string line;

        getline(cin >> ws, line);
        vector<ll> v;
        istringstream ss(line);
        ll a, b, c;
        while(ss >> a) v.push_back(a);
        if (v.size() == 2) {
            int l = v[0] + 1, r = v[1] + 1;
            ll ans = (l <= r)
                     ? query(1, 1, n, l, r)
                     : min(query(1, 1, n, l, n), query(1, 1, n, 1, r));
            cout << ans << "\n";
        } else {
            int l = v[0] + 1, r = v[1] + 1;
            ll val = v[2];
            if (l <= r) {
                update(1, 1, n, l, r, val);
            } else {
                update(1, 1, n, l, n, val);
                update(1, 1, n, 1, r, val);
            }
        }
    }
    return 0;
}
