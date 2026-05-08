#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        int sum = 0; for (int i=0; i<n; i++) sum += a[i];
        if (sum % 2 == 1) cout << "YES\n";
        else {
            if (n*k % 2 == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}