#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[35][4][4];

void preComp() {
    for (int L=0; L<4; L++) for (int R=0; R<4; R++) dp[0][L][R] = (L==2 ? 1: 0) + (R==2 ? 1 : 0);
    for (int k=1; k<=30; k++) {
        for (int L=0; L<4; L++) {
            for (int R=0; R<4; R++) {
                int M=L^R;
                dp[k][L][R] = dp[k-1][L][M] + dp[k-1][M][R] - (M==2 ? 1 : 0);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preComp();
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s, z; cin >> s >> z;
        ll cnt[4]= {0};
        for (int i=0; i<n; i++) {
            int u = (s[i]-'0')*2 + (z[i]-'0');
            cnt[u]++;
        }

        ll ans=0;
        for (int u=0; u<4; u++) {
            if (cnt[u]==0) continue;
            for (int v=0; v<4; v++) {
                if (cnt[v]==0) continue;
                int cL = ((u>>1) << 1) | (v>>1);
                int cR = ((u& 1) << 1) | (v& 1);
                ans += cnt[u]*cnt[v]* dp[k][cL][cR];
            }
        }

        cout << ans << "\n";
    }
}