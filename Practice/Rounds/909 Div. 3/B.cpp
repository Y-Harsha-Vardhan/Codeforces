#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> posK; ll ans = -1;
        for (int i=1; i<=sqrt(n); i++) {
            if (n%i == 0) {
                posK.push_back(i);
                if (i != n/i) posK.push_back(n/i);
            } 
        } sort(posK.begin(), posK.end());
        for (int k: posK) {
            ll mx=-1e18, mn=1e18;
            for (int i=0; i<n; i+=k) {
                ll sum = 0;
                for (int j=i; j<i+k; j++) sum += a[j];
                mx = max(mx, sum); mn = min(mn, sum);
            }
            ans = max(ans, mx-mn);
        }

        cout << ans << "\n";
    }
}