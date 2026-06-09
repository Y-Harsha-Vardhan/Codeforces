#include <bits/stdc++.h>
using namespace std;

int cnt(string& s, char c) {
    if (s.size()==1) return s[0]!=c;
    int m = s.size()/2; 
    string left = string(s.begin(), s.begin()+m);
    string right = string(s.begin()+m, s.end());
    
    int cntLeft = cnt(left, c+1); cntLeft += m - count(right.begin(), right.end(), c);
    int cntRight = cnt(right, c+1); cntRight += m - count(left.begin(), left.end(), c);
    return min(cntLeft, cntRight);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        cout << cnt(s, 'a') << "\n";
    }
}