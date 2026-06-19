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
        ll ans = 0;
        for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) ans = max(ans, a[i]^a[j]); 
        cout << ans << "\n";
    }
}