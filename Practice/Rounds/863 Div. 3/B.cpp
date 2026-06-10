#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
        int layer1 = min({x1, y1, n+1-x1, n+1-y1});
        int layer2 = min({x2, y2, n+1-x2, n+1-y2});

        cout << abs(layer1-layer2) << "\n";
    }
}