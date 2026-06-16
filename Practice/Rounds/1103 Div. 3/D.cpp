#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<pair<int, int>> p = {{a[0], 1}};
        for (int i=1; i<n; i++) {
            if (a[i] == a[i-1]) p.back().second++;
            else p.emplace_back(a[i], 1);
        }
        
        while (p.size()>0) {
            n = p.size();
            if (p[n-1].second%2 ==0) {cout << "YES\n"; break;}
            if (n==1) {cout << "NO\n"; break;}
            if (p[n-1].first - p[n-2].first<=k) {cout << "YES\n"; break;}
            p.pop_back();
        }
        continue;
    }
}