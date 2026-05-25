#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        
        ll sum = 0; int maxMin = 0;
        for (int i=0; i<n; i++) {
            sum += max(a[i], b[i]);
            maxMin = max(maxMin, min(a[i], b[i]));
        }

        cout << sum + maxMin << "\n";
    }
}