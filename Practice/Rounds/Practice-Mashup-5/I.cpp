#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(k); for (int i=0; i<k; i++) cin >> b[i];
        sort(a.rbegin(), a.rend()); sort(b.begin(), b.end());
        int ind=0; ll ans = 0;
        for (int i=0; i<k; i++) {
            int x = b[i];
            if (ind+x <=n) {
                for (int j=0; j<x-1; j++) ans+=a[ind+j];
                ind += x;
            } else break;
        }
        
        for (int i=ind; i<n; i++) ans += a[i];
        cout << ans << "\n";
    }
}