#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> b(n-1); for (int i=0; i<n-1; i++) cin >> b[i];
        vector<int> a(n); a[0] = b[0]; a[n-1] = b[n-2];
        for (int i=n-2; i>0; i--) a[i] = min(b[i-1], b[i]);

        for (int i=0; i<n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}