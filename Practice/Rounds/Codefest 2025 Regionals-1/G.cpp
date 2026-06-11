#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
        for(ll j = 0; j < n; j++){
            dp[0][j] = 1;
            if(j > 0) dp[0][j] = (dp[0][j] + dp[0][j-1]) %MOD;
        }

        for(ll i = 1; i < n; i++){
            ll total_prev = dp[i-1][n-1];
            
            for(ll j = 0; j < n; j++){
                ll current_val = total_prev;
                if(j >= 2) current_val = (current_val - dp[i-1][j-2] + MOD) % MOD;
                dp[i][j] = current_val;
                if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;    
            }
        }

        cout << dp[n-1][n-1] << '\n';
    }
}