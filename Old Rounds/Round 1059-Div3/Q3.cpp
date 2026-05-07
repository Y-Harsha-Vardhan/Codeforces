#include <bits/stdc++.h>
using namespace std;

int getMSB(int n) {
    if (n == 0) return -1;
    int pos=0;

    while ((1 << (pos+1)) <= n && pos<30) pos++;
    return pos;
}

void solve() {
    int a; int b;
    cin >> a >> b;

    if (a == b) {cout << "0" << endl; return;}
    if (getMSB(a) < getMSB(b)) {cout << "-1" << endl; return;}

    int diff = a^b;
    if (diff <= a) {
        cout << "1" << endl;
        cout << diff << endl;
        return;
    }

    int x1 = b&(~a);
    int interm_a = a ^ x1;
    int x2 = interm_a ^ b;

    cout << "2" << endl;
    cout << x1 << " " << x2 << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}