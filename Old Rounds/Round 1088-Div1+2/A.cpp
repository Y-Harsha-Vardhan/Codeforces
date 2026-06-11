#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n); for (int i=0; i<n; i++) cin >> p[i];
        int ans;
        if (n == 1) ans = 1;
        else ans = 2;

        for (int i=0; i<n; i++) cout << ans << " ";
        cout << "\n";
    }
}