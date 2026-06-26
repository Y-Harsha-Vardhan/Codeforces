#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; vector<ll> ans(n);
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        set<ll> b; for (int i=0; i<n; i++) {int x; cin >> x; b.insert(x);}
        bool pos=true;
        for (int i=0; i<n; i++) {
            auto it = b.lower_bound(a[i]);
            if (it == b.end()) {pos = false; break;}
            ans[i] = *it;
            b.erase(it);
        }

        if (!pos) {cout << "-1\n"; continue;}
        int cnt=0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (ans[i]>ans[j]) cnt++;
            }
        }

        cout << cnt << "\n";
    }
}