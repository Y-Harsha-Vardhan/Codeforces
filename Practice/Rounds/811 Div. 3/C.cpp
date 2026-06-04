#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int s; cin >> s;
        vector<int> num; int x = 9;
        while (true) {
            if (s-x <= 0) {
                num.push_back(s);
                break;
            }
            num.push_back(x);
            s -= x;
            x--;
        } sort(num.begin(), num.end());
        for (int i=0; i<num.size(); i++) cout << num[i] << "";
        cout << "\n";
    }
}