#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll ans = (c-a)+(d-b) - max(0LL, min(c,d)-max(a,b));
        cout << ans << "\n";
    }
}