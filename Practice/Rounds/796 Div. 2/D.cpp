#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll k; cin >> n >> k;
        vector<ll> a(n+1); for (int i=1; i<=n; i++) {cin >> a[i]; a[i] += a[i-1];}
        if (k>=n) cout << a[n] + (k-1ll+k-n)*n/2 << "\n";
        else {
            ll mx = a[k];
            for (int i=k+1; i<=n; i++) mx = max((ll)mx, a[i]-a[i-k]);
            cout << mx + k*(k-1ll)/2 << "\n";
        }
    }
}