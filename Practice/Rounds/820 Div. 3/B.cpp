#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        string t; cin >> t;
        int i = n-1; string ans;
        while (i >= 0) {
            if (t[i] == '0') {
                int x = (t[i-2]-'0')*10 + (t[i-1]-'0');
                char c = (char)('a' + x-1);
                ans = ans + c;
                i -= 3;
            }
            else {
                int x = t[i]-'0';
                char c = (char)('a' + x-1);
                ans = ans + c;
                i -= 1;
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}