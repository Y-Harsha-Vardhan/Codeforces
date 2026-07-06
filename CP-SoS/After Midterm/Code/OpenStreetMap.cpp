#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a, b, g, x, y, z;
vector<deque<ll>> deq;
vector<vector<ll>> mi;
vector<int> power;
const ll MAX_V = 1000000000000000ll;

void ins(deque<ll>& de, ll val){
    while(!de.empty() && de.back() > val) de.pop_back();
    de.push_back(val);
}

void del(deque<ll>& de, ll val) {
    if (!de.empty() && de.front() == val) de.pop_front();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> a >> b >> g >> x >> y >> z;
    mi.resize(n);
    deq.resize(m);

    for (int i=0; i<n; i++) {
        mi[i].resize(m);
        for(int j=0; j<m; j++) {
            mi[i][j] = g;
            g = (g*x+y)%z;
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<a; j++) ins(deq[i], mi[j][i]);
    }
    deque<ll> real_deq;
    for(int i=0; i<b; i++) ins(real_deq, deq[i].front());
    ll ans = 0;

    ans += real_deq.front();
    for (int i = b; i < m; i++) {
        del(real_deq, deq[i - b].front());
        ins(real_deq, deq[i].front());
        ans += real_deq.front();
    }

    for (int i = a; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            ins(deq[j], mi[i][j]);
            del(deq[j], mi[i - a][j]);
        }
        deque<ll> real_d;
        for (int j = 0; j < b; j++) {
            ins(real_d, deq[j].front());
        }
        ans += real_d.front();
        for (int j = b; j < m; j++) {
            del(real_d, deq[j - b].front());
            ins(real_d, deq[j].front());
            ans += real_d.front();
        }
    }

    cout << ans << "\n";
}