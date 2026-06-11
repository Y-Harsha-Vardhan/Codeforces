#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<ll> a(n+1, 0); for (int i=0; i<n; i++) {ll x; cin >> x; a[i+1] =a[i]+x;}
        string s; cin >> s;

        ll ans = 0;
        int l=0, r=n-1;
        while (r>l ) {
            while (l<n && s[l]=='R') l++;
            while (r>=0 && s[r]=='L') r--;
            if (l<r) {
                ans += a[r+1]-a[l];
                l++; r--;
            }
        }

        cout << ans << "\n";
    }
}