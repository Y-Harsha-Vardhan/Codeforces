#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, x, y, z; cin >> n >> x >> y >> z;
        int time1 = (n+x+y-1)/(x+y), time2;
        if (n<=z*x) time2 = (n+x-1)/x;
        else {
            int rem = n-(z*x);
            int extra = (rem + x+10*y-1)/(x+10*y);
            time2 = z + extra;
        }
        
        cout << min(time1, time2) << "\n";
    }
}