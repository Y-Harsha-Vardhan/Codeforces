#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if (k == n*n-1) cout << "NO\n";
        else {
            cout << "YES\n"; string s;
            for (int i=0; i<n; i++) {
                s = "";
                for (int j=0; j<n; j++) {
                    if (k>0) {s+="U"; k--;}
                    else if (i==n-1 && j==n-1) s+="L";
                    else if (i==n-1) s+="R";
                    else s+="D";
                }
                cout << s << "\n";
            }
        }
    }
}