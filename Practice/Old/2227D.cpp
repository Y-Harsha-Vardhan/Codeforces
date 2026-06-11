#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int solve(int l, int r) {
    set<int> s;
    for(int i = 0; i <= n; i++) s.insert(i);

    while(l >= 0 && r < 2 * n && v[l] == v[r]) {
        s.erase(v[l]);
        l--, r++;
    }

    return *s.begin();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        v = vector<int> (2 * n);
        for(auto &it : v) cin >> it;

        int x = -1, y;
        for(int i = 0; i < 2 * n; i++) {
            if(!v[i]) {
                if(~x) y = i;
                else x = i;
            }
        }

        cout << max({solve(x, x), solve(y, y), solve((x + y) / 2, (x + y + 1) / 2)}) << endl;
    }
}