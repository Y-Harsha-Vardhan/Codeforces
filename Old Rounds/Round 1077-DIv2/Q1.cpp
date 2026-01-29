#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        int l=1, r=n;

        for (int i=n-1; i>=0; i--) {
            int s = n-1-i;
            if (s%2 == 0) {a[i] = r; r--;}
            else {a[i] = l; l++;}
        }

        for (int x : a) cout << x << " ";
        cout << endl;
        
    }
}