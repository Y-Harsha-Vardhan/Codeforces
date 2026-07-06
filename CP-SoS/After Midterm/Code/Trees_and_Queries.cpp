#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
const int LIM = 17;
const int INF = (int)1e9 + 7;

vector<int> adj[MAX_N + 5];
int depth[MAX_N + 5];
int par[MAX_N + 5][LIM + 1];

void build(int cur, int p)
{
	int i;

	depth[cur] = depth[p] + 1;
	par[cur][0] = p;
	for (i = 1; i <= LIM; i++)
		par[cur][i] = par[par[cur][i - 1]][i - 1];

	for (int x : adj[cur])
		if (x != p)
			build(x, cur);
}

int lca_len(int a, int b)
{
	int i, len = 0;

	if (depth[a] > depth[b])
		swap(a, b);
	for (i = LIM; i >= 0; i--)
	{
		if (depth[par[b][i]] >= depth[a])
		{
			b = par[b][i];
			len += (1 << i);
		}
	}
	
	if (a == b)
		return len;
	for (i = LIM; i >= 0; i--)
	{
		if (par[a][i] != par[b][i])
		{
			a = par[a][i];
			b = par[b][i];
			len += (1 << (i + 1));
		}
	}
	return len + 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, i;
	cin >> n;
	
	for (i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	build(1, 0);

	cin >> t;
	while (t--)
	{
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		
        int without = lca_len(a, b);
		int with = min(lca_len(a, x) + lca_len(y, b), lca_len(a, y) + lca_len(x, b)) + 1;
		int ans = INF;

		if (without % 2 == k % 2) ans = without;
		if (with % 2 == k % 2)	ans = min(ans, with);
		
        cout << (ans <= k ? "YES" : "NO") << '\n';
	}
}