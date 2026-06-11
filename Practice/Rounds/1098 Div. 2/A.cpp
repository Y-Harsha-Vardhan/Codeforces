#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> w(n); int a=0, b=0, c=0;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (x == 0) a++;
            else if (x == 1) b++;
            else c++;
            w[i] = x;
        }

        int ans = 0; ans += a;
        if (b >= c) {
            ans += c;
            b = b-c;
            ans += b/3;
        }
        else {
            ans += b;
            c = c-b;
            ans += c/3;
        }
        
        cout << ans << "\n";
    }
}