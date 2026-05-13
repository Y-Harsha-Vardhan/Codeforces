#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<ll> f(n), a(n); for (int i=0; i<n; i++) cin >> f[i];
        bool ok = true;
        for (int i=1; i<n-1; i++) {
            ll x = f[i+1] + f[i-1] - 2*f[i];
            if (x%2) ok = false;
            a[i] = x/2; if (abs(a[i]) > 1000) ok = false;
        }

        ll left = f[n-1]; for (int i=1; i<n-1; i++) left -= a[i]*(n-1-i);
        ll right = f[0]; for (int i=1; i<n-1; i++) right -= a[i]*i;
        if (left%(n-1) || right%(n-1)) ok=false;

        a[0] =left/(n-1); a[n-1] = right/(n-1);
        if (abs(a[0]) > 1000 || abs(a[n-1])>1000) ok=false;

        if (!ok) cout << "-1\n";
        else {
            for (int i=0; i<n; i++) cout << a[i] << " "; 
            cout << "\n";
        }
    }
}