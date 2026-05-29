#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll l, r, x; cin >> l >> r >> x;
        ll a, b; cin >> a >> b;

        ll ans = -1;
        if (abs(a-b) >= x) ans = 1; // a == b
        else if (abs(a-b) == 0) ans = 0; // a -> b
        else { // a -> ... -> b
            if (min(a,b)-l>=x || r-max(a,b)>=x) {ans = 2; goto a;} // a -> c -> b

            bool alrb = (a-l>=x) && (r-b>=x); // a -> l -> r -> b
            bool arlb = (r-a>=x) && (b-l>=x); // a -> r -> l -> b
            if (alrb || arlb) ans = 3;
        }

        a:
        cout << ans << "\n";
    }
}