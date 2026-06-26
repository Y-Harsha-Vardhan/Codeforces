#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; ll h; cin >> n >> m >> h;
        vector<ll> a(n), ans(n); for (int i=0; i<n; i++) {cin >> a[i]; ans[i] = a[i];}
        vector<int> b(m); vector<ll> c(m); vector<int> changeInd;
        for (int i=0; i<m; i++) {cin >> b[i]; ll x; cin >> x; c[i] = h-x;}
        for (int i=0; i<m; i++) {
            int j = b[i]-1;
            if (ans[j] > c[i]) {
                for (int k=0; k<changeInd.size(); k++) {
                    int x = changeInd[k]; int y = b[x]-1; 
                    ans[y] = a[y];
                }
                changeInd.clear();
            } else {ans[j] += h-c[i]; changeInd.push_back(i);}
        }

        for (int i=0; i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}