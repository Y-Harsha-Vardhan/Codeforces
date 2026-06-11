#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(3*n+1); 
        for (int i=1; i<=n; i++) {
            a[3*i-2] = i;
            a[3*i-1] = n + 2*i - 1;
            a[3*i] = n + 2*i;
        }
        for (int i=1; i<=3*n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}