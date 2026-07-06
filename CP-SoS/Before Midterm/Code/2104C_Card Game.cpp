#include <bits/stdc++.h>
using namespace std;

bool beats(int n, int x, int y) {
    if (x == 0) return y == n - 1;
    if (x == n - 1) return y != 0;
    return x > y;
}

string solve(string d) {
    int n = d.length();
    for (int i = 0; i < n; i++) {
        if (d[i] != 'A') continue;

        bool good_move = true;
        for (int j = 0; j < n; j++) {
            if (d[j] == 'B' && beats(n, j, i)) {
                good_move = false;
                break;
            }
        }
        if (good_move) return "Alice\n";
    }
    return "Bob\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string d; cin >> d;
        cout << solve(d);
    }
}