#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    string nt = t;

    for (char c : s) {
        auto pos = nt.find(c);
        if (pos == string::npos) {cout << "Impossible\n"; return;}
        nt.erase(pos, 1);
    }

    sort(nt.begin(), nt.end());
    string ans;
    int i = 0, j = 0;
    while (i < s.size() && j < nt.size()) {
        if (s[i] <= nt[j]) ans += s[i++];
        else if (s[i] > nt[j]) ans += nt[j++];
    }

    ans += s.substr(i);
    ans += nt.substr(j);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}