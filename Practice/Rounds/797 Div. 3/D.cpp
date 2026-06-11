#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> w(n+1); for (int i=1; i<=n; i++) w[i] = w[i-1] + int(s[i-1] == 'W');
        int ans = INT_MAX;
        for (int i=k; i<=n; i++) ans = min(ans, w[i]-w[i-k]);

        cout << ans << "\n";
    }
}