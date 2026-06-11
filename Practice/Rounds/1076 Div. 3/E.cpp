#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n+1); for (int i=1; i<=n; i++) cin >> a[i];
        vector<int> dp(n+1, 1e9); for (int i=1; i<=n; i++) dp[a[i]] = 1;

        vector<vector<int>> divisors(n+1); 
        for (int i=1; i<=n; i++) for (int j=i; j<=n; j+=i) divisors[j].push_back(i);
        
        for (int x=1; x<=n; x++) for (int y: divisors[x]) dp[x] = min(dp[x], dp[y] + dp[x/y]); 
        for (int x=1; x<=n; x++) if (dp[x] == 1e9) dp[x] = -1;
        for (int i=1; i<=n; i++) cout << dp[i] << " ";
        cout << "\n";
    }
}