#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s; for (char& c: s) c = tolower((unsigned char)c);
        s.erase(unique(s.begin(), s.end()), s.end());

        if (s == "meow") cout << "YES\n";
        else cout << "NO\n";
    }
}