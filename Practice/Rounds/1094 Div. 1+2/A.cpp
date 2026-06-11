#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); bool ok = false;
        for (int i=0; i<n; i++) {
            int x; cin >> x; 
            if (x == 100) ok = true;
            a[i] = x;
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}