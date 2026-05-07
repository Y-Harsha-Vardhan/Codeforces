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
        int cnt=0;
        vector<ll> val(n); val[n-1] = a[n-1];
        if (val[n-1] > 0) cnt++;

        for (int i=n-2; i>=0; i--) {
            ll x = a[i];
            ll y = a[i] + val[i+1];
            val[i] = max(x, y);
            if (val[i] > 0) cnt++;
        } 

        cout << cnt << "\n";
    }
}