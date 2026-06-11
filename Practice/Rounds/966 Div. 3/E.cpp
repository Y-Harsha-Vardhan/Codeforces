#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int w; cin >> w;
        vector<ll> a(w); for (int i=0; i<w; i++) cin >> a[i];
        sort(a.rbegin(), a.rend());

        vector<ll> p; p.reserve(n*m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ll row = min(i, n-k) - max(-1, i-k);
                ll col = min(j, m-k) - max(-1, j-k);
                p.push_back(row*col);
            }
        } 

        sort(p.rbegin(), p.rend());
        ll sum = 0;
        for (int i=0; i<w; i++) sum += p[i]*a[i];
        cout << sum << "\n";
    }
}