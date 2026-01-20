#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int num0 = 0, num1 = 0;
        vector<int> a(n); 
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (a[i] == 0) num0++;
            if (a[i] == 1) num1++;
        }

        if (num0 == 0) cout << "NO\n";
        else if (num1 == 0 && num0 >= 2) cout << "NO\n";
        else cout << "YES\n";
    }
}