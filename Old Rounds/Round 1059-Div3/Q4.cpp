#include <bits/stdc++.h>
using namespace std;

long long query(int type, int l, int r) {
    cout << type << " " << l << " " << r << endl << flush;
    long long res;
    cin >> res;
    return res; 
}

void solve() {
    int n; cin >> n;

    int low = 1, high = n;
    int l_ANS = n+1;

    while (low <= high) {
        int mid = low + (high-low)/2;
        long long sum_P = query(1, 1, mid);
        long long sum_A = query(2, 1, mid);

        if (sum_A > sum_P) {
            l_ANS = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    long long sum_P_tot = query(1, 1, n);
    long long sum_A_tot = query(2, 1, n);

    long long len = sum_A_tot - sum_P_tot;
    int r_ANS = l_ANS + len-1;
    
    cout << "! " << l_ANS << " " << r_ANS << endl << flush;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}