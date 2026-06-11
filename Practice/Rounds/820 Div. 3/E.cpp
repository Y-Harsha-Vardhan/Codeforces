#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ask(int a, int b) {
    cout << "? " << a << " " << b << "\n";
    ll x; cin >> x;
    return x;
}

ll solve() {
    for (int i=2; i<=26; i++) {
        ll x = ask(1, i);
        ll y = ask(i, 1);

        if (x ==-1) return i-1;
        if (x != y) return x+y;
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    ll ans = solve();
    cout << "! " << ans << "\n";
}