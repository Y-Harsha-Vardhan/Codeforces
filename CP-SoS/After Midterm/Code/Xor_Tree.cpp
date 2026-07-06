#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int bit) {
    if (bit < 0 || v.size() <= 1)
        return v.size();

    vector<int> zero, one;
    zero.reserve(v.size());
    one.reserve(v.size());

    for (int x : v) {
        if (x & (1 << bit)) one.push_back(x);
        else zero.push_back(x);
    }

    int res = 0;
    if (!zero.empty()) {
        int keep0 = solve(zero, bit - 1);
        res = max(res, keep0 + (one.empty() ? 0 : 1));
    }
    if (!one.empty()) {
        int keep1 = solve(one, bit - 1);
        res = max(res, keep1 + (zero.empty() ? 0 : 1));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;

    int keep = solve(v, 30);
    cout << (n - keep) << "\n";

    return 0;
}
