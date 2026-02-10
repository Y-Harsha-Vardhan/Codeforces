#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> mask(n, 0);
        for (int i=0; i<k; i++) {
            string s; cin >> s;
            for (int j=0; j<n; j++) mask[j] |= (1 << (s[j]-'a')); // efficiently store data
        }
        vector<int> div; 
        for (int d=1; d*d<=n; d++) {
            if (n%d == 0) {
                div.push_back(d);
                if (d*d != n) div.push_back(n/d);
            }
        }
        sort(div.begin(), div.end());

        string ans;
        for (int d: div) {
            string blk(d, '?');
            bool ok = true;

            for (int i=0; i<d && ok; i++) {
                int interm = (1 << 26) - 1;
                for (int pos=i; pos<n; pos+=d) interm &= mask[pos];

                if (interm==0) {ok=false; break;}

                int x = __builtin_ctz(interm);
                blk[i] = char('a' +x);
            } 
            if (ok) {
                ans = "";
                for (int i=0; i<n; i++) ans += blk[i%d];
                break;
            }
        }
        cout << ans << "\n";
    }
}
