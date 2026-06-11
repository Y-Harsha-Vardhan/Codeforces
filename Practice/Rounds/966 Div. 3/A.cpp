#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        int n; cin >> n;
        if (n <= 101) {cout << "NO\n"; continue;}
        string s = to_string(n); int x = stoi(s.substr(2));
        if (s[0] != '1' || s[1] != '0' || s[2] == '0' || x < 2) {cout << "NO\n"; continue;}
        cout << "YES\n";
    }
    
}