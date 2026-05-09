#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        a[0] = n-1, a[1] = n;
        for (int i=2; i<n; i++) a[i] = n-i;
        for (int i=0; i<n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}