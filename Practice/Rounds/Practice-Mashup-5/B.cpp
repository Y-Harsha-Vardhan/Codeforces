#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n+1); a[0] = 0;
        for (int i=1; i<=n; i++) cin >> a[i];
        vector<int> ans;
        for (int i=0; i<n; i++) {
            ll diff = a[i+1]-a[i];
            if ((ll)i-diff >=0) ans.push_back(ans[i-diff]);
            else ans.push_back(i+1);
        }

        for (int x: ans) cout << x << " ";
        cout << "\n";
    }
}