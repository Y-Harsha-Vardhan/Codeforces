#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();

    vector<bool> vis(m, false);
    for (int i=0; i<m; i++) {
        ll val = a[i];
        for (ll j=2*val;; j+=val) {
            if (j > a.back()) {
                if (j <= k) {cout << -1 << "\n"; return;}
                break;
            }

            auto it = lower_bound(a.begin(), a.end(), j);
            if (it != a.end() && *it == j) {
                int ind = distance(a.begin(), it);
                vis[ind] = true;
            }
            else {cout << -1 << "\n"; return;}
        }
    }

    vector<ll> b;
    for (int i=0; i<m; i++) {
        if (!vis[i]) b.push_back(a[i]);
    }

    cout << b.size() << "\n";
    for (int i=0; i<b.size(); i++) cout << b[i] << (i ==b.size()-1 ? "" : " ");
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}