#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << pow(2, n)-1 << " ";
        for (int i=1; i<=n; i++) {
            for (int j=0; j<pow(2, i); j+=2) {
                cout << (j+1)*pow(2, n-i)-1 << " ";
            }
        }
        cout << "\n";
    }
}