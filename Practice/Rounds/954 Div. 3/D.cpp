#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int ans=1e9; 
        for (int i=0; i<n-1; i++) {
            int currSum=0; bool hasZero=false;
            for (int j=0; j<n; j++) {
                int x = s[j]-'0';
                if (j==i) {
                    x = x*10 + (s[j+1]-'0');
                    j++;
                }

                if (x == 0) hasZero=true;
                else if (x>1) currSum+=x;
            }

            if (hasZero) {ans=0; break;}
            if (currSum == 0 ) ans = min(ans, 1);
            else ans = min(ans, currSum);
        }

        cout << ans << "\n";
    }
}