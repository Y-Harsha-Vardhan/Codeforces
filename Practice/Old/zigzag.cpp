#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int MAX = -1; int count = 0;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            MAX = max(MAX, x);
            if (i%2 == 1) a[i] = MAX;
            else a[i] = x; 
        }

        
        for (int i=0; i<n; i++) {
            if (i%2 == 1) continue;
            if (i == 0) count += max(0, a[0]-a[1]+1); 
            else if (i == n-1) count += max(0, a[n-1]-a[n-2]+1);

            else count += max(0, a[i] - min(a[i-1], a[i+1]) + 1);
        }

        cout << count << "\n";
    }
}