#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(k+1); for (int i=1; i<=k; i++) cin >> a[i];
        vector<vector<int>> pos(max(n, k) +1);
        for (int i=1; i<=n; i++) { int x; cin >> x; pos[x].push_back(i);}
        vector<int> ans;
        for (int val=k; val>=1; val--) {
            int rep = k-val+1;
            for (int p: pos[val]) for (int j=0; j<rep; j++) ans.push_back(p);
        }

        cout << ans.size() << "\n";
        for (int x: ans) cout << x << " ";
        cout << "\n";
    }
}