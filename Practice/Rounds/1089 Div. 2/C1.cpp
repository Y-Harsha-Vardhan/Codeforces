#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n+1); for (int i=1; i<=n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        int ans = 0;
        for (int i=1; i<=n; i++) {
            bool cond = false;
            if (i == 1) {if (gcd(a[i], a[i+1]) < a[1]) cond = true;}
            else if (i == n) {if (gcd(a[i-1], a[i]) < a[i]) cond = true;}
            else {
                int A = gcd(a[i-1], a[i]), B = gcd(a[i], a[i+1]);
                if (lcm(A, B) < a[i]) cond = true;
            }

            if (cond) ans++;
        }

        cout << ans << "\n";
    }
}