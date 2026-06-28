#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; ll s=0; int ans=0;
        vector<ll> a(n); for (int i=0; i<n; i++) {cin >> a[i]; s^=a[i];}
        if (n == 1) {cout << "0\n"; continue;}
        if (!s) {cout << "1\n"; continue;}
        for (int i=0; i<n; i++) if ((s^a[i]) < a[i]) ans++;
        cout << ans << "\n";
    }
}