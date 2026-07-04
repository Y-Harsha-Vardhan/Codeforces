#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s; string res=""; // make 1111000001111 -> 101
        for (char c: s) if (res.empty() || c!=res.back()) res.push_back(c);

        if (res.length() == 1) cout << "1\n";
        else if (res.length() == 2) cout << "2\n";
        else cout << "1\n";
    }
}