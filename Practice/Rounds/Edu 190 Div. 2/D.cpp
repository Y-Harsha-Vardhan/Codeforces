#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        vector<int> g(n+2, n-1); ll ans = 0;

        for (int i=n-1; i>=0; i--) {
            if (a[i]==b[i]) g[a[i]] = g[a[i]+1];
            else {
                g[a[i]] = i-1;
                g[b[i]] = i-1;
            }
            ans += max(0, g[1]-i+1);
        }

        cout << ans << "\n";
    }
}