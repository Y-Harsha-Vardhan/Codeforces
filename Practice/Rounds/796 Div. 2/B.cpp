#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) {int x; cin >> x; a[i] = __builtin_ffs(x)-1;}
        int r; r = max(*(min_element(a.begin(), a.end()))-1, 0);
        for (int x: a) r+= (x>0);
        cout << r << "\n";        
    }
}