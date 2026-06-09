#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        vector<int> a(3); for (int i=0; i<3; i++) cin >> a[i];
        sort(a.rbegin(), a.rend());
        if (a[0] != a[1]) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << a[0] << " " << a[2] << " " << a[2] << "\n";
        }
    }
}