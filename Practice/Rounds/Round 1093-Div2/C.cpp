#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll p, q; cin >> p >> q;
        ll T = p + 2*q; bool pos = false;
        for (ll n=1; n*(2*n+1)<=T; n++) {
            if ((T-n)%(2*n+1) != 0) continue;
            ll m = (T-n)/(2*n+1);
            if (m>0 && abs(m-n)<=p) {pos = true; cout << m << " " << n << "\n"; break;}
            if (n>0 && abs(n-m)<=p) {pos = true; cout << n << " " << m << "\n"; break;}
        }
        if (!pos) cout << -1 << "\n";
    }
}