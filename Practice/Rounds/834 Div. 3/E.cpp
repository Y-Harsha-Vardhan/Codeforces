#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll test(vector<ll> a, ll h, vector<int> op) {
    int used=0, cnt=0;
    for (ll x: a) {
        while (h<=x && used<3) {
            if (op[used] == 2) h*=2; // G
            else h*=3; // B
            used++;
        }

        if (h<=x) break; // need serum
        h += x/2;
        cnt++;
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll h; cin >> n >> h;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end()); ll ans = 0;
        vector<int> ggb={2,2,3}, gbg={2,3,2}, bgg={3,2,2}; // G->G->B, G->B->G, B->G->G
        ans = max(ans, test(a, h, ggb));
        ans = max(ans, test(a, h, gbg));
        ans = max(ans, test(a, h, bgg));

        cout << ans << "\n";
    }
}