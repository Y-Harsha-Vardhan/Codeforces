#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++)cin >> a[i];
        vector<int> b = a; sort(b.begin(), b.end(), greater<int>());

        int i;
        for (i=0; i<n; i++) if (a[i] != b[i]) break;
        if (i == n) {for (int i=0; i<n; i++) cout << a[i] << " "; cout << "\n"; continue;}
        else {
            int j; for (j=0; j<n; j++) if (a[j] == b[i]) break;
            reverse(a.begin()+i, a.begin()+j+1);
            for (int i=0; i<n; i++) cout << a[i] << " "; 
            cout << "\n";
        }
    }
}