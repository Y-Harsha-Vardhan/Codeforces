#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> h(n); for (int i=0; i<n; i++) cin >> h[i];
        int x = *max_element(h.begin(), h.end());
        int y = *min_element(h.begin(), h.end());

        cout << x-y+1 << "\n";
    }
}