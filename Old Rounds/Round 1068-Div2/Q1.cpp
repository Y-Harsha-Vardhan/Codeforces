#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int slpCnt = 0, cool = 0;
        for (char c : s) {
            if (c == '1') cool = k;
            else {
                if (cool > 0) cool--;
                else slpCnt++;
            }
        }
        cout << slpCnt << "\n";
    }
}