#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<bool> suffUniq(n); set<int> uniq; uniq.insert(a[n-1]); suffUniq[n-1] = true;
        for (int i=n-2; i>=0; i--) {
            uniq.insert(a[i]);
            suffUniq[i] = (uniq.size() == n-i);
        }

        for (int i=0; i<n; i++) if (suffUniq[i]) {cout << i << "\n"; break;}
    }
}