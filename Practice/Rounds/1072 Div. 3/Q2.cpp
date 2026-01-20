#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int s, k, m; cin >> s >> k >> m;
        int r = m%k; int d = m/k;
        if (k >= s) {
            int x = m - k*d;
            if (x > s) cout << "0\n";
            else cout << s-x << "\n";
        }
        else {
            m = m % (2*k);
            if (m <= k-1) cout << s-m << "\n";
            else cout << 2*k-m << "\n";
        }
    }
}