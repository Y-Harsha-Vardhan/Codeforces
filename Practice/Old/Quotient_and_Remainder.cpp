#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPos(int c, const vector<ll>& q, const vector<ll>& r, ll k) {
    for (int i=0; i<c; i++) {
        ll a = q[i]+1; ll b = r[c-1-i]+1;
        if (a*b - 1 > k) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll k; cin >> n >> k;
        vector<ll> q(n), r(n);
        for (ll &x : q) cin >> x;
        for (ll &x : r) cin >> x;

        sort(q.begin(), q.end());
        sort(r.begin(), r.end());

        int low = 0, high = n;
        while (low < high) {
            int mid = (low+high+1)/2;
            if (isPos(mid, q, r, k)) low = mid;
            else high = mid-1;
        }
        cout << low << "\n";
    }
}