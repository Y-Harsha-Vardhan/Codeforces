#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        int x = a[0], y = a[n-1];
        if (x==-1 && y==-1) {x=0; y=0;}
        else if (x == -1) x = y;
        else if (y == -1) y = x;
        a[0] =x; a[n-1] = y;

        cout << abs(x-y) << "\n";
        for (int i=0; i<n; i++) cout << (a[i]==-1 ? 0 : a[i]) << " ";
        cout << "\n";
    }
}