#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string a; cin >> a;
        int m; cin >> m;
        string b; cin >> b;
        string c; cin >> c;

        for (int i=0; i<m; i++) {
            if (c[i] == 'V') a = b[i] + a; 
            if (c[i] == 'D') a = a + b[i]; 
        }
        cout << a << "\n";
    }
}