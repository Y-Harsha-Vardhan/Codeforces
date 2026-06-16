#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int a, b, x; cin >> a >> b >> x;
        int ans = INT_MAX, cnt=0;
        while (a != b) {
            if (b>a) swap(a, b);
            ans = min(ans, abs(a-b)+cnt);
            a /= x;
            cnt++;
        }
        
        ans = min(ans, cnt);
        cout << ans << "\n";
    }
}