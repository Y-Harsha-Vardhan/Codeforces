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
        vector<ll> even, odd; for (int i=0; i<n; i++) (a[i]%2==0 ? even.push_back(a[i]) : odd.push_back(a[i]));
        // large odd, then all even, then remaining odd in optimal manner
        if (odd.size() == 0) {cout << "0\n"; continue;} 
        int o = odd.size(), e = even.size();
        sort(odd.rbegin(), odd.rend()); ll ans = 0;
        for (int i=0; i<e; i++) ans += even[i];
        for (int i=0; i<(o+1)/2; i++) ans += odd[i];
        cout << ans << "\n";
    }
}