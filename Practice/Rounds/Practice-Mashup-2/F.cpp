#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        string X; cin >> X;
        int ind = 0;

        if (n%2 != 0) {
            if (X[0] == 'b') {
                cout << "NO\n";
                continue;
            }

            X[0] = 'a';
            ind = 1;
        }

        bool pos = true;
        for (int i=ind; i<n; i+=2) {
            char& first = X[i]; 
            char& second = X[i+1];

            if (first == '?' && second == '?') first = 'a', second = 'b';
            else if (first == '?') first = ((second == 'a') ? 'b' : 'a');
            else if (second == '?') second = ((first == 'a') ? 'b' : 'a');
            else if (first == second) pos = false;
        }

        if (!pos) cout << "NO\n";
        else cout << "YES\n";
    }
}