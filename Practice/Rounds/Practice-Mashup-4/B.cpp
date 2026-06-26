#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> ones, zeros;
        for (int i=0; i<n; i++) (s[i]=='1' ? ones.push_back(i+1) : zeros.push_back(i+1));
        int num0 = zeros.size(), num1 = ones.size();
        
        if (num0%2 == 1) {
            cout << num0 << "\n";
            for (int i=0; i<num0; i++) cout << zeros[i] << " ";
            cout << "\n";
        } else if (num1%2 == 0) {
            cout << num1 << "\n";
            if (num1!=0) {   
                for (int i=0; i<num1; i++) cout << ones[i] << " ";
                cout << "\n";
            }
        } else cout << "-1\n";
    }
}