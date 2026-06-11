#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, x, s; cin >> n >> x >> s;
        string u; cin >> u;
        vector<int> dp(x+1, -1); dp[0]=0;
        for (int i=0; i<n; i++) {
            vector<int> temp = dp;
            for (int j=0; j<=x; j++) {
                if (dp[j]==-1) continue;
                int val = dp[j];
                int E=x-j, P=j*s-val;

                if (u[i] =='I') {if (E>0) temp[j+1] = max(temp[j+1], val+1);}
                else if (u[i] == 'E') {if (P>0) temp[j] = max(temp[j], val+1);}
                else if (u[i] == 'A') {
                    if (E>0) temp[j+1] = max(temp[j+1], val+1);
                    if (P>0) temp[j] = max(temp[j], val+1);
                }
            }
            dp = temp;
        }

        int mx=0; 
        for (int j=0; j<=x; j++) mx = max(mx, dp[j]);
        cout << mx << "\n";
    }
}