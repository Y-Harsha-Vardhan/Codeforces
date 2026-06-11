#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        ll l = k-1, r = n-k;
        ll X = min(l, r); 
        ll Y = max(l, r);
        
        if (3*X <= m+1) {
            ll R = (m+1-X)/2;
            R = min(R, Y);
            cout << X+R+1 << "\n";
        }
        else {
            ll v = (m+1)/3;
            ll ans = 2*v+1;
            if (3*v+2 <= m+1) ans++;
            cout << ans << "\n";
        }
    }
}