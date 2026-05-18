#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool possible(ll x, ll a, ll k) {
    ll carry=0;
    for (int bit=59; bit>=0; bit--) {
        carry *= 2;
        if ((x >> bit) & 1) carry++;
        if ((a >> bit) & 1) carry -= min(k, carry);
    }
    return (carry == 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll s, m; cin >> s >> m;
        if (!possible(s, m, (1LL<<60))) cout << -1 << "\n";
        else {
            ll left = 0, right = (1LL<<60);
            while (left<=right) {
                ll mid = (left+right)/2;
                if (possible(s, m, mid)) right = mid-1;
                else left = mid+1;
            }
            cout << left << "\n";
        }
    }
}