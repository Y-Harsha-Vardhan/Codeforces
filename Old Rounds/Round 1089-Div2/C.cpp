#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int cnt = 0;
    for (char c: a) if (c == '(') cnt++;
    for (char c: b) if (c == '(') cnt++;

    if (cnt != n) {cout << "NO\n"; return;}
    int bal1 = 0, bal2 = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == '(') {bal1++; bal2++;}
            else {bal1--; bal2--;}
        }
        else {
            if (bal1 < bal2) {bal1++; bal2--;}
            else {bal1--; bal2++;}
        }
        if (bal1 < 0 || bal2 < 0) {cout << "NO\n"; return;}
    }

    cout << "YES\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}
