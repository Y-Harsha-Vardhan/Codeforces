#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ans(2*n+1); ans[0]=0;
        for (int i=n-1; i>=1; i--) {
            ans[n-i+1] = i;
            ans[n+i+1] = i;
        } ans[1] = n; ans[n+1] = n;

        for (int i=1; i<=2*n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}