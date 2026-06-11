#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string yes = ""; 
    for (int i=0; i<100; i++) yes = yes + "Yes";
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        if (yes.find(s) < yes.size()) cout << "YES\n";
        else cout << "NO\n";
    }
}