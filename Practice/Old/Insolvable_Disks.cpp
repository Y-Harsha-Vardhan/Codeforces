#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<int> x(n); for (int i=0; i<n; i++) cin >> x[i];
        int ans = n-1, l = 0, r= +1e9+1, cur=0, fst=1;
        for (int i=1; i<n; i++) {
            cur = (x[i]-x[i-1]) - cur;
            if (i%2 == fst%2) {
                r = min(r, cur);
                if (i<n-1) l = max(l, cur-(x[i+1]-x[i]));
            }
            else {
                l = max(l, -cur);
                if (i<n-1) r = min(r, (x[i+1]-x[i]) - cur);
            }

            if (l>=r) {
                ans--; l=0; r=+1e9+1; cur=0; fst=i+1;
            }
        } 
        cout << ans << "\n";
    }
}