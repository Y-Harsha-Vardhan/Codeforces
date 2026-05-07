#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s1, s2; cin >> s1 >> s2;

        vector<int> dp(n+1, INT_MAX); dp[0] = 0;
        for (int i=1; i<=n; i++) {
            int cv = (s1[i-1] != s2[i-1]) ? 1 : 0;
            if (dp[i-1] != INT_MAX) dp[i] = min(dp[i], dp[i-1]+cv);
            if (i>= 2 && dp[i-2]!=INT_MAX) {
                int ch = (s1[i-2] != s1[i-1] ? 1 : 0) + (s2[i-2] != s2[i-1] ? 1: 0);
                dp[i] = min(dp[i], dp[i-2]+ch);
            } 
        }
        cout << dp[n] << "\n";
    }
}