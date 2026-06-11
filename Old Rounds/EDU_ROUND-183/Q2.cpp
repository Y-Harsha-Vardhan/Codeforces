#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;

        if (n == k) {
            cout << string(n, '-') << "\n";
            continue;
        }
        
        int a=0, b=0, c=0;
        for (char x : s) {
            if (x == '0') a++;
            else if (x == '1') b++;
            else c++;
        }

        string result(n, '?');
        for (int i=0; i<a; i++) result[i] = '-';
        for (int i=0; i<b; i++) result[n-1-i] = '-';

        int plus_start = a+c;
        int plus_end = n-b-c-1;

        if (plus_start <= plus_end) {
            for (int i=plus_start; i<=plus_end; i++) result[i] = '+';
        }

        cout << result << "\n";
    }
}