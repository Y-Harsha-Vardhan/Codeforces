#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, c, d; cin >> n >> c >> d;
        int p[100005];
        set<int> st;
        ll sol = 0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (st.count(x)) sol += c;
            else st.insert(x);
        } 

        int x = 0;
        for (int s : st) p[++x] = s;
        ll ans = LLONG_MAX;

        for (int i=1; i<=x; i++) {
            ll cost = 1LL * (p[i] - i) * d + 1LL * (x - i) * c;
            ans = min(ans, cost);
        }
        ans = min(ans, 1LL*x*c + d);
        cout << ans + sol << "\n";
    }
}