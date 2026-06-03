#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> s(n); for (int i=0; i<n; i++) cin >> s[i];
        vector<int> f(n); for (int i=0; i<n; i++) cin >> f[i];
        int currTime = 0; vector<int> d(n);
        for (int i=0; i<n; i++) {
            currTime = max(currTime, s[i]);
            d[i] = f[i]-currTime;
            currTime = f[i];
        }

        for (int x: d) cout << x << " ";
        cout << "\n";
    }
}