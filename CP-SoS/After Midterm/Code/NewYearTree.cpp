#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1'200'300;

int n, m;
vector<int> color, parentOrder, tin, tout, euler;
vector<vector<int>> tree;
vector<pair<int,int>> queries;

vector<ll> seg, lazy;

void dfs(int u, int p) {
    tin[u] = euler.size();
    euler.push_back(u);
    for (int v : tree[u]) if (v != p) dfs(v, u);
    tout[u] = euler.size();
}

void build(int idx, int L, int R) {
    lazy[idx] = -1;
    if (L + 1 == R) {
        seg[idx] = (1LL << color[euler[L]]);
    } else {
        int mid = (L + R) / 2;
        build(2*idx+1, L, mid);
        build(2*idx+2, mid, R);
        seg[idx] = seg[2*idx+1] | seg[2*idx+2];
    }
}

void apply(int idx, ll mask) {
    seg[idx] = mask;
    lazy[idx] = mask;
}

void push(int idx) {
    if (lazy[idx] >= 0) {
        apply(2*idx+1, lazy[idx]);
        apply(2*idx+2, lazy[idx]);
        lazy[idx] = -1;
    }
}

void update(int idx, int L, int R, int ql, int qr, ll mask) {
    if (ql >= R || qr <= L) return;
    if (ql <= L && R <= qr) {
        apply(idx, mask);
        return;
    }
    push(idx);
    int mid = (L + R) / 2;
    update(2*idx+1, L, mid, ql, qr, mask);
    update(2*idx+2, mid, R, ql, qr, mask);
    seg[idx] = seg[2*idx+1] | seg[2*idx+2];
}

ll query(int idx, int L, int R, int ql, int qr) {
    if (ql >= R || qr <= L) return 0;
    if (ql <= L && R <= qr) return seg[idx];
    push(idx);
    int mid = (L + R) / 2;
    return query(2*idx+1, L, mid, ql, qr)
         | query(2*idx+2, mid, R, ql, qr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        color.assign(n, 0);
        tree.assign(n, {});
        queries.resize(m);

        for (int i = 0; i < n; i++)
            cin >> color[i];

        for (int i = 0, u, v; i < n - 1; i++) {
            cin >> u >> v;
            tree[u-1].push_back(v-1);
            tree[v-1].push_back(u-1);
        }

        vector<tuple<int,int,int>> ops(m);
        for (int i = 0, t, v, c; i < m; i++) {
            cin >> t >> v;
            if (t == 1) {
                cin >> c;
                ops[i] = {1, v-1, c};
            } else {
                ops[i] = {2, v-1, 0};
            }
        }

        tin.resize(n);
        tout.resize(n);
        euler.clear();
        dfs(0, -1);

        int N = euler.size();
        seg.assign(4*N, 0);
        lazy.assign(4*N, -1);
        build(0, 0, N);

        for (auto &[t, v, c] : ops) {
            int l = tin[v], r = tout[v];
            if (t == 1) {
                update(0, 0, N, l, r, (1LL << c));
            } else {
                ll mask = query(0, 0, N, l, r);
                cout << __builtin_popcountll(mask) << "\n";
            }
        }
    }

    return 0;
}
