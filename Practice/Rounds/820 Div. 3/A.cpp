#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int timeA = abs(a-1);
        int timeB = abs(c-b) + abs(c-1);

        if (timeA == timeB) cout << 3 << "\n";
        else if (timeA < timeB) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}