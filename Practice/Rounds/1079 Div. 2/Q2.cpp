#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n); for (int i=0; i<n; i++) cin >> p[i];
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        
        vector<int> aN;
        for (int i=0; i<n; i++) {
            if (aN.empty() || aN.back()!=a[i]) aN.push_back(a[i]);
        }

        int j=0;
        for (int i=0; i<n; i++) {
            if (j<aN.size() && p[i]== aN[j]) j++;
        }

        if (j==aN.size()) cout << "YES\n";
        else cout << "NO\n";
    }
}