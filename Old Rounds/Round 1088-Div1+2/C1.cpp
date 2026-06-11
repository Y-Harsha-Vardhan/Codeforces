#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];

        int x = n-k, y = k-1;
        vector<bool> in(n+1, false), used(n+1, false);
        if (x <= y) for (int i=x; i<=y; i++) in[a[i]] = true;

        string ans = "YES";
        for (int i=0; i<n; i++) {
            bool isMid = (i>=x && i<=y);
            if (!isMid) {
                if (b[i]!=-1 && b[i]!=a[i]) {ans = "NO"; break;}  
            }
            else {
                if (b[i]!=-1) {
                    if (!in[b[i]]) {ans = "NO"; break;}
                    if (used[b[i]]) {ans = "NO"; break;}
                    used[b[i]] = true;
                }
            }
        }

        cout << ans << "\n";
    }
}