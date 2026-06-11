#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> div2, div3, div6, rem;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (x%6 == 0) div6.push_back(x);
            else if (x%2 ==0) div2.push_back(x);
            else if (x%3 == 0) div3.push_back(x);
            else rem.push_back(x);
        }

        vector<int> ans;
        for (int x: div6) ans.push_back(x);
        for (int x: div2) ans.push_back(x);
        for (int x: rem) ans.push_back(x);
        for (int x: div3) ans.push_back(x);

        for (int i=0; i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}