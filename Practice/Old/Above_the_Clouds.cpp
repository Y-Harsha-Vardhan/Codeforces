#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    unordered_map<char, int> data;
    string s; cin >> s;
    for (int i=0; i<n; i++) data[s[i]]++;
    char first = s[0], last = s[n-1];

    for (int i=0; i<n; i++) {
        if (data[s[i]] >= 3) {cout << "Yes\n"; return;}
        else if (data[s[i]] == 2 && ((first != s[i]) || (last != s[i]))) {cout << "Yes\n"; return;}
    }
    
    cout << "No\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}