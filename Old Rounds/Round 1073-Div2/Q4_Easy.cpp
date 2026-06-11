#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int numPrefix = 0;
        while (numPrefix<n && s[numPrefix]=='(') numPrefix++;

        if (numPrefix <= n/2 - 2) cout << n-2 << "\n";
        else cout << -1 << "\n";
    }
}