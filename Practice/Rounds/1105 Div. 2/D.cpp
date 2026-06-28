#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, d; cin >> n >> d;
        vector<ll> a(3*n+1); for (int i=1; i<=n; i++) {cin >> a[i]; a[i+n] = a[i]; a[i+2*n] = a[i];}
        vector<ll> pref(3*n+1, 0); for (int i=1; i<=3*n; i++) pref[i] = pref[i-1]+a[i];
        ll ans = 0;
        for (int i=n+1; i<=2*n; i++) {
            ll val = 1LL*(2*d+1)*a[i] - (pref[i+d]-pref[i-d-1]);
            if (val>0) ans+=val;
        }

        cout << ans << "\n";
    }
}