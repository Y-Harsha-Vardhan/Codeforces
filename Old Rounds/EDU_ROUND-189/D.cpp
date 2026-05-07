#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

ll countVal(ll N, int m) {
    if (N < m) return 0;
    return (N-m)/4+1;
}

ll countMOD4(ll L, ll R, int m) {
    if (L> R) return 0;
    return countVal(R, m) - (L>0 ? countVal(L-1, m) : 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, x; cin >> n >> x;
        ll a0 = countMOD4(0, x-1, 3)+1; ll b0 = countMOD4(x, n, 3);
        ll a1 = countMOD4(0, x-1, 1); ll b1 = countMOD4(x, n, 1);
        ll t1 = (a0%MOD)*(b0%MOD); ll t2 = (a1%MOD)*(b1%MOD);
        
        __int128 tot = t1; tot += t2;
        ll ans = tot % MOD;
        cout << ans << "\n";
    }
}