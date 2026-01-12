#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<bool> vis(n+2, false);
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (x<n+2) vis[x]=true;
        }

        int mex = 0;
        while (vis[mex]) mex++;
        cout << min(mex, k-1) << "\n";
    }
}