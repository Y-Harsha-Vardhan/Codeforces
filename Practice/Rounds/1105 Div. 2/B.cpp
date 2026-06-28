#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;

ll modPow(ll b, ll e) {
    ll res=1; b%= MOD;
    while (e>0) {
        if (e&1) res = res*b%MOD;
        b = b*b%MOD;
        e >>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n,m,r,c; cin >> n >> m >> r >> c;
        ll ans = modPow(2, n*m-(n-r+1)*(m-c+1));
        
        cout << ans << "\n";
    }
}