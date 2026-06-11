#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2e5+5;
int pref[maxN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        ll ans = 0;
        for (int i=0; i<n; i++) {
            pref[i+1] = pref[i];
            if (s[i] == '0') pref[i+1]--;
            else pref[i+1]++;
        }
        for (int i=1; i<=n; i++) ans += (ll)i * (n-i+1);
        sort(pref, pref+n+1);
        for (int i=0; i<=n; i++) ans += (ll)pref[i] * (i-(n-i));
        cout << ans/2 << "\n";
    }
}