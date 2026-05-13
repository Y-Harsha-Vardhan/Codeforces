#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        vector<int> opt(n+1); opt[n] = max(a[n-1], b[n-1]);
        for (int i=n-2; i>=0; i--) opt[i+1] = max({a[i], b[i], opt[i+2]});

        vector<int> pref(n+1, 0); for (int i=1; i<=n; i++) pref[i] = pref[i-1] + opt[i];
        for (int i=0; i<q; i++) {
            int l, r; cin >> l >> r;
            cout << pref[r] - pref[l-1] << " ";
        }
        cout << "\n";
    }
}