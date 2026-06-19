#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll Ax, Ay, Bx, By; cin >> n >> Ax >> Ay >> Bx >> By;
        vector<ll> dp[2]; dp[0] = dp[1] = vector<ll> (n+5, 0);
        map<ll, ll> mx, mn; mn[Ax] = mx[Ax] = Ay;   mn[Bx] = mx[Bx] = By;
        vector<ll> x(n+5); for (int i=0; i<n; i++) cin >> x[i];
        vector<ll> y(n+5); for (int i=0; i<n; i++) cin >> y[i];
        for (int i=0; i<n; i++) {
            mx[x[i]] = max(mx[x[i]], y[i]);
            if (!mn.count(x[i])) mn[x[i]] = y[i];
            else mn[x[i]] = min(mn[x[i]], y[i]);
        }
        int lst=Ax, cnt=0;
        for (auto i: mx) {
            if (i.first == Ax) {dp[0][0] = dp[1][0] = 0; continue;}
            int need = (i.first -lst) + (mx[i.first]-mn[i.first]);
            cnt++;
            dp[0][cnt] = min(dp[0][cnt - 1] + abs(mx[i.first] - mn[lst]), dp[1][cnt - 1] + abs(mx[i.first] - mx[lst])) + need;
            dp[1][cnt] = min(dp[0][cnt - 1] + abs(mn[i.first] - mn[lst]), dp[1][cnt - 1] + abs(mn[i.first] - mx[lst])) + need;
            lst = i.first;
        }

        cout << dp[0][cnt] << "\n";
    }
}