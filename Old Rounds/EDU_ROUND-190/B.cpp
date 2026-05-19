#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int fours=0, total2= 0;
        vector<char> sp; 
        for (char c: s) {
            if (c=='4') fours++;
            else {
                sp.push_back(c);
                if (c== '2') total2++;
            }
        }

        int left13 = 0, right2 = total2, best=right2;
        for (char c: sp) {
            if (c== '2') right2--;
            else left13++;
            best = min(best, left13+right2);
        }

        cout << fours+best << "\n";
    }
}