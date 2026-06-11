#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 2000001;
const int INF = 1e9;

vector<int> bit;
int bit_size;

void bit_update(int i, int delta) {
    for (++i; i<=bit_size; i+= i&-i) bit[i] += delta;
}

int bit_query(int i) {
    int sum=0;
    for (++i; i>0; i-=i&-i) sum += bit[i];
    return sum;
}

vector<int> tree, lazy;
int n;

void build(int node, int start, int end) {
    lazy[node] = 0;
    if (start == end) {
        tree[node] = bit_query(start)-start;
        return;
    }

    int mid = (start + end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);

    tree[node] = min(tree[2*node], tree[node*2 +1]);
}

void push(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node];

    if (start != end) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node]; 
    }
    lazy[node] = 0;
}

void range_update(int node, int start, int end, int l, int r, int val) {
    push(node, start, end);
    if (start>end || start>r || end<l) return;
    
    if (l<=start && end<=r) {
        lazy[node] += val;
        push(node, start, end);
        return;
    }

    int mid = (start + end)/2;
    range_update(node*2, start, mid, l, r, val);
    range_update(2*node+1, mid+1, end, l, r, val);

    tree[node] = min(tree[2*node], tree[node*2+1]);
}

int query_first0(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if (start>end || start>r || end<l || tree[node]>0) return -1;

    if (start == end) return (tree[node] == 0) ? start : -1;

    int mid = (start+end)/2;
    push(2*node, start, mid);

    if (tree[node*2] <= 0) {
        int res = query_first0(node*2, start, mid, l, r);
        if (res != -1) return res;
    }

    push(2*node+1, mid+1, end);
    if (tree[node*2+1] <= 0) return query_first0(2*node+1, mid+1, end, l, r);

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ac, dr; cin >> ac >> dr;
    cin >> n;

    vector<int> a(n), d(n), costs(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> d[i];

    bit_size = n + MAX_VAL + 1;
    bit.assign(bit_size+1, 0);

    for (int i=0; i<n; i++) {
        costs[i] = max(0, a[i]-ac) + max(0, d[i]-dr);
        bit_update(costs[i], 1);
    }

    tree.assign((n+1)*4, 0);
    lazy.assign((n+1)*4, 0);
    build(1, 0, n);


    int m; 
    cin >> m;

    while (m--) {
        int k, na, nd;
        cin >> k >> na >> nd;
        --k;

        int old_cost = costs[k];
        int new_cost = max(0, na-ac) + max(0, nd-dr);
        costs[k] = new_cost;

        bit_update(old_cost, -1);
        bit_update(new_cost, 1);

        if (old_cost <= n) range_update(1, 0, n, old_cost, n, -1);
        if (new_cost <= n) range_update(1, 0, n, new_cost, n, 1);

        int p0 = bit_query(0);
        int final_p = query_first0(1, 0, n, p0, n);

        if (final_p == -1) final_p = bit_query(n + MAX_VAL);


        cout << final_p << "\n";
    }
}