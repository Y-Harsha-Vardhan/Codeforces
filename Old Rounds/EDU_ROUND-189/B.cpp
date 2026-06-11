#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int vp= 0, n = s.length();
        for (int i=0; i<n-1; i++) if (s[i] == s[i+1]) vp++;

        if (vp<= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}