#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<long long> queries(q);
    for (int i=0; i<q; i++) cin >> queries[i];

    bool hasB = false;
    for (char c : s) if (c == 'B') {hasB = true; break;}

    for (int i=0; i<q; i++) {
        long long a = queries[i];

        if (!hasB) cout << a << "\n";
        else {
            long long currA = a;
            long long sec = 0;
            int machInd = 0;

            while (currA > 0) {
                sec++;

                if (s[machInd] == 'A') currA--;
                else currA /= 2;

                machInd = (machInd + 1)%n;
            }
            cout << sec << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) solve();
}