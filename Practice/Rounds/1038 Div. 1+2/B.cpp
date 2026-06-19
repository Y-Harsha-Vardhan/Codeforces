#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n), b(n), c(n), d(n);
        for (int i=0; i<n; i++) {cin >> a[i] >> b[i] >> c[i] >> d[i];}
        ll ans=0;
        for (int i=0; i<n; i++) {
            if (b[i]>d[i]) ans += a[i]+b[i]-d[i];
            else ans += max(0LL, a[i]-c[i]);
        }

        cout << ans << "\n";
    }
}