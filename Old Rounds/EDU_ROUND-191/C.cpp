#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n>> k;
        string s; cin >> s;
        int totR=0; for (char c: s) if (c==')') totR++;
        int L=0, R=totR; 
        int minCost = n+1, split=0;
        for (int p=0; p<=n; p++) {
            int cost = L+R;
            if (cost < minCost) {
                minCost = cost;
                split = p;
            }
            if (p<n) {
                if (s[p]=='(') L++;
                else R--;
            }
        }
        int M =minCost; int numRem= min(k, M);
        string ans(n, '0');
        for (int i=0; i<n; i++) {
            if (numRem==0) break;
            if (i<split && s[i]=='(') {
                ans[i] ='1';
                numRem--;
            } else if (i>=split && s[i] ==')') {
                ans[i]='1';
                numRem--;
            }
        }

        cout << ans << "\n";
    }
}