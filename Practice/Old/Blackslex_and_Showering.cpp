#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n+1, 0); for (int i=1; i<=n; i++) cin >> a[i];
        int totSum = 0; for (int i=2; i<=n; i++) totSum += abs(a[i]-a[i-1]);

        vector<int> dp(n+1, 0); int mn = INT_MAX;
        for (int i=1; i<=n; i++) {
            if (i==1) dp[i] = totSum - abs(a[i+1]-a[i]);
            else if (i == n) dp[i] = totSum - abs(a[i]-a[i-1]);
            else {
                dp[i] = totSum + abs(a[i+1]-a[i-1]) - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]);
            }

            mn = min(mn, dp[i]);
        }
        cout << mn << "\n";
    }
}