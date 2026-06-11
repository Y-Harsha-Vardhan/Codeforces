#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int cal(int x) {
    return abs(x-a) + abs(x-b) + abs(x-c);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int x = (a+b+c)/3;
        int ans = min(cal(x), cal(a));
        ans = min(ans, cal(b));
        ans = min(ans, cal(c));
        
        cout << ans << "\n";
    }
}