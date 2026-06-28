#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll ans = 0;
        for (int i=0; i<=30; i++) {
            ll val = 1LL << i;
            ll num = min(n/val, k);
            ans += num;
            n -= num*val;
        }

        cout << ans << "\n";
    }
}