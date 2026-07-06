#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int INF = (int)2e9;

vector<int> adj[MAX_N];
int inTree[MAX_N];
int depth[MAX_N];
vector<int> bit[MAX_N];
int inRoot = 0;

void dfs(int v, int d, int num, int p)
{
	int i;
	inTree[v] = num;
	depth[v] = d;
	bit[num].push_back(0);

	for (i = 0; i < adj[v].size(); i++)
	{
		int to = adj[v][i];
		if (to == p) continue;
		dfs(to, d + 1, num, v);
	}
}

void add(int p, int val, int num)
{
	for (int i = p; i < bit[num].size(); i += (i & -i))
		bit[num][i] += val;
}

int find(int p, int num)
{
	int res = 0;
	for (int i = p; i > 0; i -= (i & -i))
		res += bit[num][i];
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q, i;
	cin >> n >> q;

	for (i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int root_children = adj[0].size();
	for (i = 0; i < root_children; i++)
	{
		bit[i].push_back(0);
		dfs(adj[0][i], 1, i, 0);
	}
	bit[root_children].resize(n + 10);

	while (q--)
	{
		int type;
		cin >> type;
		if (type == 0)
		{
			int v, val, dist;
			cin >> v >> val >> dist;
			v--;

			if (v == 0)
			{
				inRoot += val;
				add(1, val, root_children);
				add(dist + 1, -val, root_children);
			}
			else
			{
				if (dist >= depth[v])
				{
					int left = dist - depth[v];
					inRoot += val;
					add(1, val, root_children);
					add(left + 1, -val, root_children);
					add(left + 1, val, inTree[v]);
					add(depth[v] + dist + 1, -val, inTree[v]);
				}
				else
				{
					add(depth[v] - dist, val, inTree[v]);
					add(depth[v] + dist + 1, -val, inTree[v]);
				}
			}
		}
		else
		{
			int v;
			cin >> v;
			v--;

			if (v == 0)
				cout << inRoot << '\n';
			else
			{
				int res = find(depth[v], inTree[v]) + find(depth[v], root_children);
				cout << res << '\n';
			}
		}
	}

	return 0;
}
