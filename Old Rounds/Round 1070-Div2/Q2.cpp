#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> a;
    for (int i=0; i<n; i++) if (s[i] == '1') a.push_back(i);
    int maxDist = 0, k = a.size();
    if (k == 0) {cout << "0\n"; return;}
    for (int i=0; i<k; i++) {
        int cur = a[i];
        int nxt = a[(i+1)%k];
        int d;
        if (nxt > cur) d = nxt - cur;
        else d = n + nxt - cur;

        if (d > maxDist) maxDist = d;
    }

    cout << maxDist-1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}