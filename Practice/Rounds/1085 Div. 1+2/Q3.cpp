#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll h; cin >> n >> h;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<ll> cnt(n);
        for (int i=0; i<n; i++) {
            ll curr = a[i]; cnt[i] = h-curr;
            for (int j=i+1; j<n; j++) curr = max(curr, a[j]), cnt[i] += h-curr;
            curr = a[i];
            for (int j=i-1; j>=0; j--) curr = max(curr, a[j]), cnt[i]+= h-curr;
        }

        ll ans=0;
        for (int i=0; i<n; i++) {
            ll mx = a[i], arg=i; 
            for (int j=i; j<n; j++) {
                if (a[j] > mx) mx=a[j], arg=j;
                ans = max(cnt[i]+cnt[j]-cnt[arg], ans);
            }
        }

        cout << ans << "\n";
    }
}