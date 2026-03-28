#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); 
        int ans = 0, curMax=0;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (x >= curMax) {
                ans++;
                curMax = x;
            }
        }
        cout << ans << "\n";
    }
}