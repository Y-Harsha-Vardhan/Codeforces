#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; ll sum = 0; 
        vector<ll> a(n); for (int i=0; i<n; i++) {cin >> a[i]; sum+=a[i];}
        vector<ll> suffMin(n); suffMin[n-1] = a[n-1]; sum -= suffMin[n-1];
        for (int i=n-2; i>=0; i--) {
            suffMin[i] = min(suffMin[i+1], a[i]);
            sum -= suffMin[i];
        }
        ll mx=-1, curr=1;
        for (int i=1; i<n; i++) {
            if (suffMin[i] == suffMin[i-1]) curr++;
            else {
                mx =max(mx, curr);
                curr=1;
            }
        }

        mx = max(mx, curr);
        cout << sum+mx-1 << "\n";
    }
}