#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<ll> c(n); for (int i=0; i<n; i++) cin >> c[i];
        ll ans=0, cnt=0, ones=0;
        for (int i=n-1; i>=0; i--) {
            if (c[i]>1) {ans+= c[i]; cnt += (c[i]-2)/2;}
            else {ones = i+1; break;}
        }

        ll res = 0;
        if (ones == n-1) res = ans+min(ones, ans/2);
        else res = ans + min(ones, cnt);

        if (res >=3) cout << res << "\n";
        else cout << 0 << "\n";
    }
}