#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, H, M; cin >> n >> H >> M;
        int sleep = H*60 + M;
        int best = 1440;

        for (int i=0; i<n; i++) {
            int h, m; cin >> h >> m;
            int alarm = h*60 + m;
            int d = (alarm-sleep + 24*60)%(24*60);
            best = min(best, d);
        }

        cout << best/60 << " " << best%60 << "\n";
    }
}