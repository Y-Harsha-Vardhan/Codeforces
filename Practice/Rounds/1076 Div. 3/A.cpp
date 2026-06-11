#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, s, x; cin >> n >> s >> x;
        vector<int> a(n); int sum = 0; 
        for (int i=0; i<n; i++) {cin >> a[i]; sum += a[i];}
        if (s-sum < 0) {cout << "NO\n"; continue;}
        cout << (((s-sum)%x == 0) ? "YES\n" : "NO\n");
    }
}