#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];

        bool pos = true;
        for (int i=0; i<n-1; i++) {
            if (a[i]%2 == a[i+1]%2) {pos=false; break;}
        }
        
        if (pos) cout << "YES\n";
        else cout << "NO\n";
    }
}