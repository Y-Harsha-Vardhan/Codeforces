#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int k, int n, const vector<int>& a, const vector<int>& b, int mn, int mx) {
    ll low = (ll)mx - k;
    ll up = (ll)mn + k;

    for (int i=0; i<n; i++) {
        if (a[i]>low && a[i]<up && a[i]!=b[i]) return false;  
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b = a;
        sort(b.begin(), b.end());

        bool s = true;
        for (int i=0; i<n; i++) {
            if (a[i] != b[i]) {
                s = false;
                break;
            }
        }

        if (s) {cout << -1 << "\n"; continue;}
        int mn = b[0], mx = b[n-1];
        int l=1, h=1e9;
        int ans = 1;
        while (l <= h) {
            int m = l + (h-l)/2;
            if (check(m, n, a, b, mn, mx)) {
                ans = m;
                l = m+1;
            }
            else h = m-1;
        }

        cout << ans << "\n";
    }
}