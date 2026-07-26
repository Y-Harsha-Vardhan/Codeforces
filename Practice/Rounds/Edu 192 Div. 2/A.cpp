#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        vector<int> c(k); for (int i=0; i<k; i++) cin >> c[i];
        // either using same character -> atleast 3 
        // or using distinct character -> atleast 2 of each
        bool isPos = false; vector<int> num2;
        for (int i=0; i<k; i++) {
            if (c[i] >= 3) {isPos = true; break;}
            if (c[i]==2) num2.push_back(i);
        }
        if (num2.size() >= 2) isPos = true;
        cout << (isPos ? "YES\n" : "NO\n");
    } 
}