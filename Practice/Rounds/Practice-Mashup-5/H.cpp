#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n), pos0, used(n);
        for (int i=0; i<n; i++) {
            cin >> p[i]; p[i]--; 
            if (p[i]==-1) pos0.push_back(i);
            else used[p[i]] = 1;
        }
        if (pos0.size() == 1) {
            int unused=0; for (int i=0; i<n; i++) if (used[i]==0) unused=i;
            p[pos0[0]] = unused;
        }
        int l=0, r=n-1;
        while (l<n && p[l]==l) l++;
        while (r>=0 && p[r]==r) r--;
        cout << max(0, r-l+1) << "\n";
    }
}