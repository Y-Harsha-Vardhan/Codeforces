#include <bits/stdc++.h>
using namespace std;

int firstLayer(int h) {
    int n = (h+1)/2;
    int x = (pow(4, n) - 1) / 3;
    return x;
}

int secLayer (int h) {
    int n = h/2;
    int x = 2*(pow(4, n) - 1) / 3;
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int cas1 = 1, cas2 = 1;
        while (true) {
            if (firstLayer(cas1)<=a && secLayer(cas1)<=b) cas1++;
            else break;
        }
        
        while (true) {
            if (firstLayer(cas2)<=b && secLayer(cas2)<=a) cas2++;
            else break;
        }

        cout << max(cas1, cas2)-1 << "\n";
    }
}