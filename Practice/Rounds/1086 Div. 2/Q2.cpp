#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k, p;
        ll m;
        cin >> n >> k >> p >> m;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll ap = a[p-1];

        vector<ll> pref(a.begin(), a.begin() + (p-1));
        sort(pref.begin(), pref.end());

        ll sum_pref = 0;
        for (ll x : pref) sum_pref += x;

        ll keep = 0;
        int take = max(0, k-1);

        for (int i = max(0, (int)pref.size() - take); i < (int)pref.size(); i++) {
            keep += pref[i];
        }

        ll A = sum_pref - keep;
        m -= (A + ap);

        if (m < 0) {
            cout << 0 << "\n";
            continue;
        }

        vector<ll> b;
        for (int i = 0; i < n; i++) {
            if (i != p-1) b.push_back(a[i]);
        }

        sort(b.begin(), b.end());

        ll sum = ap;
        for (int i = 0; i < n-k; i++) {
            sum += b[i];
        }

        cout << 1 + m / sum << "\n";
    }
}