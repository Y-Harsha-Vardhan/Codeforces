#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(m); for (int i=0; i<m; i++) cin >> b[i];
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        vector<int> intersection;
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersection));
        int k = intersection.size();

        int ans = 2*min(n-k, m-k);
        if (n>m) ans+=2;
        else ans += 1;
        cout << ans << "\n";
    }
}