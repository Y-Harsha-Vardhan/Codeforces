#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >>a[i];
        int ans=0, x=-1, y=-1;
        for (int i=0; i<n; i++) {
            if (ans==0 || !(x+1<=a[i] && a[i]<=y+1)) {
                ans++;
                x = a[i];
                y = a[i];
            } 
            else y=a[i];
        }

        cout << ans << "\n";
    }
}