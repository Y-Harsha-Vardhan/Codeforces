#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        bool noReorder=true; int diff=0;
        for (int i=0; i<n; i++) {
            if (a[i] < b[i]) noReorder = false;
            diff += a[i]-b[i];
        } sort(a.begin(), a.end()); sort(b.begin(), b.end());
        bool reorder = true; for (int i=0; i<n; i++) if (a[i]<b[i]) { reorder=false; break;}

        if (noReorder) cout << diff << "\n";
        else if (reorder) cout << diff+c << "\n";
        else cout << "-1\n";
    }
}