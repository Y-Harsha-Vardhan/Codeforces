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
        vector<ll> pref(n), suff(n+1); pref[0] = abs(a[0]); 
        for (int i=1; i<n; i++) pref[i] = pref[i-1] + abs(a[i]);

        suff[n-1] =a[n-1];
        for (int i=n-2; i>=0; i--) suff[i] = suff[i+1] + a[i];
        ll best = suff[0]; int ind=-1;
        for (int i=1; i<n; i++) {
            if (a[i]>0) {
                ll score = pref[i-1] + suff[i+1] - a[i];
                if (score > best) {
                    best = score;
                    ind = i;
                }
            }
        }

        if (ind == -1) {cout << "0\n\n"; continue;}
        vector<int> ans;
        for (int i=ind-1; i>=0; i--) {
            if (ans.size() & 1) a[i] = -a[i];
            if (a[i] > 0) ans.push_back(i);
        }
        ans.push_back(ind);

        cout << ans.size() << "\n";
        for (int i=0; i<ans.size(); i++) cout << ans[i]+1 << " "; 
        cout << "\n";
    }
}