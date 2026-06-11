#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        multiset<int> dp;
        for (int i=1; i<=n; i++) {
            int l, r; cin >> l >> r;
            auto it = dp.upper_bound(r);
            if (it != dp.end()) dp.erase(it);
            dp.insert(l);
            cout << dp.size() << " ";
        }
        cout << "\n";
    }
}