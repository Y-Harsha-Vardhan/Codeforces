#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll x; cin >> n >> x;
        vector<ll> a(n), b(n), c(n);
        for (int i=0; i<n; i++) cin >> a[i] >> b[i] >> c[i];
        ll start=0, mx=-1e9;
        for (int i=0; i<n; i++) {
            mx = max(mx, a[i]*b[i]-c[i]);
            start += a[i]*(b[i]-1);
        }
        x -= start;
        if (x<=0) {cout << "0\n"; continue;}
        if (mx<=0) {cout << "-1\n"; continue;}
        cout << (x+mx-1)/mx << "\n"; 
    }
}