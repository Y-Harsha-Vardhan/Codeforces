#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int numStd = 0, last = -1, first = -1, newStd = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') {
                numStd++; 
                if (last == -1) first = i;
                else {
                    int g = i-last-1;
                    newStd += g/3;
                }
                last = i;
            }
        }

        if (numStd == 0) cout << (n+2)/3 << "\n";
        else {
            int preZero = first;
            newStd += (preZero+1)/3;

            int suffZero = n-1-last;
            newStd += (suffZero+1)/3;

            cout << numStd+newStd << "\n";
        }
    }
}