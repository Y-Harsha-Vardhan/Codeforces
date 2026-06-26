#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int l=n, r=n; int cnt=0;
        while (r!=1) {
            if (l<=k && k<=r) break;
            l = l/2; r = r/2+r%2;
            cnt++;
        }

        if (l<=k && k<=r) cout << cnt << "\n";
        else cout << "-1\n";
    }
}