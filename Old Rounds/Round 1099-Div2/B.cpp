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
        ll k=0; for (int i=0; i<n-1; i++) if (a[i]>a[i+1]) k = max(k, a[i]-a[i+1]); 
        if (k == 0) {cout << "YES\n"; continue;} 
        int curr = 0; bool ok = true;
        for (int i=0; i<n-1; i++) {
            ll val = a[i]+curr*k;
            if (a[i+1] >=val) curr = 0;
            else if (a[i+1]+k>= val) curr=1;
            else ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}