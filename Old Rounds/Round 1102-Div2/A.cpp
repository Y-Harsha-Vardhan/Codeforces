#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        sort(b.rbegin(), b.rend()); bool pos = true;
        for (int i=0; i<n-2; i++) {
            if (b[i]%b[i+1] != b[i+2]) {
                pos = false;
                break;
            }
        } 

        if (pos) cout << b[0] << " " << b[1] << "\n";
        else cout << -1 << "\n";
    }
}