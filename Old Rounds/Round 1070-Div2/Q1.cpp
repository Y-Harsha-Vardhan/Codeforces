#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int &x : a) cin >> x;
        int curMax = -1, ans=0;
        for (int x : a) {
            if (x < curMax) ans++;
            else curMax = x;
        }
        cout << ans << "\n";
    }
}