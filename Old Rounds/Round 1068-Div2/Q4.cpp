#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 7;
const int maxB = 64, maxK = 32;
int dp[maxB+2][maxK+2][2];

void Min(int&x, int y) {x = min(x, y);}

void solve() {
    int n, k; cin >> n >> k;
    int pc = __builtin_popcount(n);
    if (n == 0) {cout << max(0ll, k-1) << "\n"; return;}
    if (k >= 32) {cout << k+pc-1 << "\n"; return;}

    for (int i=0; i<=maxB; i++) {
        for (int j=0; j<=k; j++) dp[i][j][0] = dp[i][j][1] = INF; 
    }
    dp[0][0][0] = 0;
    for (int i=0; i<=maxB; i++) {
        int ni = (n >> i) & 1ll;
        for (int u=0; u<=k; u++) {
            for (int c=0; c<=1; c++) {
                int curr = dp[i][u][c];
                if (curr >= INF) continue;
                {
                    int sum = ni+c, bit = sum & 1, nc = sum >> 1;
                    Min(dp[i+1][u][nc], curr+bit); 
                }
                if (u+1 <= k) {
                    int sum = ni+1+c, bit = sum&1, nc = sum >> 1;
                    Min(dp[i+1][u+1][nc], curr+bit); 
                }
            }
        }
    }
    int best = INF;
    for (int u=0; u<=k; u++) for (int c=0; c<=1; c++) {
        int val = dp[maxB][u][c];
        if (val < INF) Min(best, val+c);
    }
    int ans = k + pc - best;
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}