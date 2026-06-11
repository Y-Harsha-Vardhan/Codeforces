#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, x, y; cin >> n >> x >> y;
        vector<int> p(n); for (int i=0; i<n; i++) cin >> p[i];

        int mn = n+1, j = -1; // find min in the interior of portal
        for (int i=x; i<y; i++) {
            if (p[i] < mn) {
                mn = p[i];
                j = i;
            }
        }

        // rotate the interior such that this minimum number is in the beginning
        if (j != -1) rotate(p.begin()+x, p.begin()+j, p.begin()+y);

        // now check if there is any chance for improvement of lexicographic ordering
        vector<int> outer; 
        for (int i=0; i<x; i++) outer.push_back(p[i]);
        for (int i=y; i<n; i++) outer.push_back(p[i]);
        int k = 0;
        while (k < outer.size() && outer[k] < p[x]) {
            k++;
        }
        

        // printing answer
        for (int i=0; i<k; i++) cout << outer[i] << " ";
        for (int i=x; i<y; i++) cout << p[i] << " ";
        for (int i=k; i<outer.size(); i++) cout << outer[i] << " ";

        cout << "\n";
    }
}