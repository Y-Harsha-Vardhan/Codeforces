#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        if (s.find("2026") == string::npos && s.find("2025") != string::npos) cout << "1\n";
        else cout << "0\n";
    }
}