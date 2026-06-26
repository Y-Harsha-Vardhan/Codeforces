#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool found = false;
        int ans_x = -1, ans_y = -1;

        for (int x = 0; x < n && !found; x++) {
            for (int y = 0; y < x; y++) {
                int val = a[x] % a[y];
                if (val % 2 == 0) {
                    ans_x = x; ans_y = y;
                    found = true; break;
                }
            }
        }

        if (found) cout << a[ans_y] << " " << a[ans_x] << "\n";
        else cout << "-1\n";  
    }
}