#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> x(m); for (int i=0; i<m; i++) cin >> x[i];

        vector<ll> odd, even; ll sum = 0;
        for (int i=1; i<=n; i++) {
            sum += a[i-1];
            if (i%2 == 0) even.push_back(a[i-1]);
            else odd.push_back(a[i-1]);
        }
        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());
        int e=0, o=0; bool usedOdd=false, usedEven=false;

        for (int i=0; i<m; i++) {
            if (x[i]%2 == 1) {
                if (o<odd.size() && (odd[o]>0 || !usedOdd)) {
                    sum -= odd[o];
                    o++;
                    usedOdd = true;
                }
            }
            else {
                if (e<even.size() && (even[e]>0 || !usedEven)) {
                    sum -= even[e];
                    e++;
                    usedEven = true;
                }
            }
        }

        cout << sum << "\n";
    }
}