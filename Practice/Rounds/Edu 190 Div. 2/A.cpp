#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, a, b; cin >> n >> a >> b;
        ll x = n/3, y = n%3;
        ll ans = x*min(3*a, b);
        ans += min(b, y*a);
        cout << ans << "\n";
    }
}