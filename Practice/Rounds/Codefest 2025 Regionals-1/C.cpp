#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
    mutable int v;

    bool operator<(const Node& other) const {
        return l < other.l;
    }
};

set<Node> s;

auto split(int pos) {
    auto it = s.lower_bound({pos, 0, 0});
    if (it != s.end() && it->l == pos)
        return it;

    --it;
    int L = it->l;
    int R = it->r;
    int V = it->v;

    s.erase(it);
    s.insert({L, pos - 1, V});
    return s.insert({pos, R, V}).first;
}

void solve() {
    int n, q;
    cin >> n >> q;

    s.clear();

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        s.insert({i, i, a});
    }

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;

        auto itr = split(r + 1);
        auto itl = split(l);

        int cnt[101] = {0};

        for (auto it = itl; it != itr; ++it)
            cnt[it->v] += it->r - it->l + 1;

        s.erase(itl, itr);

        int mid_idx = (l + r) / 2;
        int ans = -1;
        int current_pos = l;

        if (type == 1) {
            for (int v = 1; v <= 100; ++v) {
                if (cnt[v] == 0) continue;

                int len = cnt[v];

                if (ans == -1 &&
                    current_pos <= mid_idx &&
                    mid_idx < current_pos + len)
                    ans = v;

                s.insert({current_pos,
                          current_pos + len - 1,
                          v});

                current_pos += len;
            }
        } else {
            for (int v = 100; v >= 1; --v) {
                if (cnt[v] == 0) continue;

                int len = cnt[v];

                if (ans == -1 &&
                    current_pos <= mid_idx &&
                    mid_idx < current_pos + len)
                    ans = v;

                s.insert({current_pos,
                          current_pos + len - 1,
                          v});

                current_pos += len;
            }
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
