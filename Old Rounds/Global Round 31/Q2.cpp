#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> a(n); for (int i=0; i<n; i++) cin >> a[i];
        string cur= a[0];
        for (int i=1; i<n; i++) {
            string prep = a[i] + cur;
            string app = cur + a[i];
            if (prep < app) cur = prep;
            else cur = app;
        }
        cout << cur << "\n";
    }
}