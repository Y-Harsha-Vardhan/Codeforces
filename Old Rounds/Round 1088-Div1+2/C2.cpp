#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];

        vector<bool> fixed(k, false);
        for (int i=0; i<k; i++) {
            for (int j=i+k; j<n; j+=k) {
                if (a[j] != a[i]) {fixed[i]=true; break;}
            }
        }

        string ans = "YES";
        vector<int> other(k, -1);
        for (int i=0; i<n; i++) {
            int c = i%k; 
            if (fixed[c]) {
                if (b[i]!=-1 && b[i]!=a[i]) {ans = "NO"; break;}
            }
            else {
                if (b[i]!= -1) {
                    if (other[c] == -1) other[c]=b[i];
                    else if (other[c] != b[i]) {ans = "NO"; break;}
                }
            }
        }

        if (ans == "NO") {cout << ans << "\n"; continue;}

        vector<int> targets(n+1, 0);
        for (int c=0; c<k; c++) if (!fixed[c]) targets[a[c]]++;
        for (int c=0; c<k; c++) {
            if (!fixed[c] && other[c]!=-1) {
                if (targets[other[c]] >0) targets[other[c]]--;
                else {ans = "NO"; break;}
            }
        }
        cout << ans << "\n";
    }
}