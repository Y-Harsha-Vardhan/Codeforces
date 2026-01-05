#include <bits/stdc++.h>
using namespace std;

bool good(const vector<int>& x, const vector<int>& y, int n, int k) {
    for (int i = 0; i < n; i++) if (x[i] <= y[(i + k) % n]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        vector<int> c(n); for (int i=0; i<n; i++) cin >> c[i];

        long long cntI = 0, cntK = 0;
        for (int i=0; i<n; i++) {
            if (good(b, a, n, i)) cntI++;
            if (good(c, b, n, i)) cntK++;
        }
        cout << cntI*cntK*n << "\n";
    }
}