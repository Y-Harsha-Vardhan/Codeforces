#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        int all=0; for (int i=0; i<n; i++) all ^= a[i]^b[i];
        if (all == 0) {cout << "Tie\n"; continue;}

        int bit, ans;
        for (int i=0; i<20; i++) if (all&1 << i) bit =i;
        for (int i=0; i<n; i++) if ((a[i]^b[i])&1 << bit) ans = i;
        cout << (ans%2 ? "Mai\n" : "Ajisai\n");
    }
}