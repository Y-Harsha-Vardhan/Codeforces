#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, d; cin >> n >> d;
        string s; cin >> s; 
        int i=0; while(i<n && s[i]>='0'+d) i++;
        s.insert(s.begin()+i, '0'+d);
        cout << s << "\n";
    }
}