#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sumDig(ll n) {
    ll s=0;
    while (n>0) {
        s+= n%10;
        n/=10;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        if (x%9 != 0) cout << "0\n";
        else {
            int cnt=0;
            for (ll y=x; y<=x+100; y++) if (y-sumDig(y) == x) cnt++;
            cout << cnt << "\n";
        }
    }
}