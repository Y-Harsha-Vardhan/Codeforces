#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int a=0, b=0;
        for (char c : s){
            if (c == '(') a++;
            else b++;
        }
        if (a == b) cout << "YES\n";
        else cout << "NO\n";
    }
}
