#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        if (adjacent_find(a.begin(), a.end()) != a.end()) cout << "-1";
        else {
            for (int i=0; i<n; i++) cout << a[i] << " ";
        }
        cout << "\n";
    }
}