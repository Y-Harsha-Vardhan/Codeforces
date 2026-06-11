#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; char c = 0;
        n = 2*n+1;
        while (n--) {
            string s; cin >> s;
            for (auto x: s) c ^= x;
        }
        cout << c << "\n";
    }
}