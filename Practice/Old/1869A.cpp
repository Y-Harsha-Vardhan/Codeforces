#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        if (n%2 == 0) {
            cout << 2 << "\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n << "\n";
        }

        else {
            cout << 4 << "\n";
            cout << 1 << " " << n-1 << "\n";
            cout << 1 << " " << n-1 << "\n";
            cout << n-1 << " " << n << "\n";
            cout << n-1 << " " << n << "\n";
        }
    }
}