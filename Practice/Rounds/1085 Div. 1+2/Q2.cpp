#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m, l; cin >> n >> m >> l;    
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> lev(m, 0);  
        int curr = n;

        for (int i = 0; i < l; i++) { 
            lev[min(m, curr + 1) - 1]++;

            sort(lev.begin(), lev.end(), greater<int>());

            if (curr > 0 && a[n - curr] - 1 == i) {
                lev[0] = 0;
                sort(lev.begin(), lev.end(), greater<int>());
                curr--;
            }
        }

        cout << lev[0] << "\n";
    }
}