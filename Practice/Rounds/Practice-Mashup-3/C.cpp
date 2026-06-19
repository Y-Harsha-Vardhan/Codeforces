#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ld> c(n+1), p(n+1); 
        for (int i=1; i<=n; i++) {
            int ci, pi;
            cin >> ci >> pi;
            c[i] = ci; p[i] = pi/100.0;
        }
        ld ans = 0;
        for (int i=n; i>=1; i--) ans = max(ans, ans*(1-p[i])+c[i]);
        cout << fixed << setprecision(10) << ans << "\n";
    }
}