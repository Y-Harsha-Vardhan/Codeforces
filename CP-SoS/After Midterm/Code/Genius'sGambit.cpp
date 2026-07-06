#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b); i-- > (a);)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return b < a ? (a = b, true) : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? (a = b, true) : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


bool construct_strings(int z, int o, int k, string &x, string &y) {
    x = string(o, '1') + string(z, '0');

    if (k == 0) {
        y = x;
        return true;
    }

    if (z == 0 || o == 1) return false;

    if (k < o) {
        y = string(o - k, '1') + '0' + string(k, '1') + string(z - 1, '0');
        return true;
    }

    if (k < o + z - 1) {
        y = "10";
        y += string(o - 2, '1');
        int zero_in_middle = k - (o - 1);
        y += string(zero_in_middle, '0') + '1';
        y += string(z - zero_in_middle - 1, '0');
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z, o, k;
    cin >> z >> o >> k;

    string x, y;
    if (!construct_strings(z, o, k, x, y)) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n" << x << '\n' << y << '\n';
    return 0;
}
