#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        swap(a[0], a[n-1]);
        sort(a.begin()+1, a.end());

        vector<int> uniqVal, dupVal;
        for (int i=1; i<n; i++) {
            if (!uniqVal.empty() && uniqVal.back()==a[i]) dupVal.push_back(a[i]);
            else uniqVal.push_back(a[i]);
        }
        vector<int> arranged; arranged.push_back(a[0]);
        for (int x: uniqVal) arranged.push_back(x);
        for (int x: dupVal) arranged.push_back(x);

        ll ans = 0; map<int, int> freq;
        int mex=0, mx=0;
        for (int x: arranged) {
            freq[x]++;
            mx = max(x, mx);
            while (freq[mex]>0) mex++;
            ans += mx + mex;
        }

        cout << ans << "\n";
    }
}