#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll lowbit(ll x) {return x & -x;}

inline bool isPowerOfTwo(ll x) {return x == lowbit(x);}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        ll l, r; cin >> l >> r;
        ll b = 1LL << 60;

        while (b > 0 && ((b & l) == (b & r))) {
            if (b & l) {l -= b; r -= b;}
            b >>= 1;
        }

        if (l && isPowerOfTwo(l + r + 1)) cout << 2LL * min(lowbit(l), lowbit(r + 1)) - 1 << "\n";
        else if (l) cout << min(lowbit(l), lowbit(r + 1)) - 1 << "\n";
        else cout << lowbit(r + 1) - 1 << "\n";
    }
}
