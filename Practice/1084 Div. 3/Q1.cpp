#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); int mx = -1;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        } 

        if (n == 1) {cout << "1\n"; continue;}
        int ans=0;
        for (int i=0; i<n; i++) if (a[i] == mx) ans++;
        cout << ans << "\n";
    }
}