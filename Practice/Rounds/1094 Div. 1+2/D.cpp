#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<pair<ll, int>> b(n+1); vector<int> p(n);
        b[0] = {0, 0};
        for (int i=1; i<=n; i++) {
            b[i].first = b[i-1].first + a[i-1];
            b[i].second = i;
        }
        for (int i=n; i>=1; i--) b[i].first = b[i-1].first;
        sort(b.begin()+1, b.end());
        for (int i=n; i>=1; i--) p[b[i].second-1] = n-i+1;
        
        for (int i=0; i<n; i++) cout << p[i] << " ";
        cout << "\n";
    }
}