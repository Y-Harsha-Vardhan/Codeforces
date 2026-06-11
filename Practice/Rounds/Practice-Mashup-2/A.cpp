#include <bits/stdc++.h>
#include <utility>
using namespace std;

int cntUgly(vector<int>& p, int n) {
    int ugly=0, mx=0;
    for (int i=1; i<=n; i++) {
        mx = max(mx, p[i]);
        if (mx == i) ugly++;
    }
    return ugly;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n+1); 
        for (int i=1; i<=n; i++) {
            cin >> p[i];
            if (p[i] == n) swap(p[1], p[i]);
        }
        
        for (int i=1; i<=n; i++) cout << p[i] << " ";
        cout << "\n";
    }
}