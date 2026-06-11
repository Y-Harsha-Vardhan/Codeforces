#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        // 2a + 4b = n -> a + 2b = n/2
        if (n%2 == 1) {cout << 0 << "\n"; continue;}
        int cnt = 0;
        for (int a=0; a<=n/2; a++) {
            if ((n/2-a)%2 == 0) cnt++;
        }
        cout << cnt << "\n";
    }
}