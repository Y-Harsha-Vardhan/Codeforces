#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2e5+5;
ll pref[maxN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll s, x; cin >> n >> s >> x;
        vector<ll> a(n+1); ll ans = 0; 
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            pref[i] = pref[i-1] + a[i];
        }
        map<ll, int> cnt;
        int l = 1;
        for (int r=1; r<=n; r++) {
            if (a[r] > x) cnt.clear(), l = r+1;
            else if (a[r] == x) {
                while (l <= r) {cnt[pref[l-1]]++; l++;}
            }
            ans += cnt[pref[r] - s];
        }
        cout << ans << "\n";
    }
}