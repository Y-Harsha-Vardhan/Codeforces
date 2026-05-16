#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        int w = x&(-x);
        while (!(w^x) || !(w&x)) w++;
        cout << w << "\n";
    }
}