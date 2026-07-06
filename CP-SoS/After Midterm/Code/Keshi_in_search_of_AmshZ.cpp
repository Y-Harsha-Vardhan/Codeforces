#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m;
int d[N], dist[N];
vector<int> adj[N];
bool mark[N];
priority_queue<pair<int, int> > pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int i;
	cin >> n >> m;

	for (i = 1; i <= n; i++)
		dist[i] = m;

	while (m--)
	{
		int u, v;
		cin >> v >> u;
		adj[u].push_back(v);
		d[v]++;
	}

	dist[n] = 0;
	pq.push(make_pair(0, n));

	while (!pq.empty())
	{
		int v = pq.top().second;
		pq.pop();

		if (mark[v])
			continue;

		mark[v] = true;

		for (i = 0; i < adj[v].size(); i++)
		{
			int u = adj[v][i];
			if (dist[v] + d[u] < dist[u])
			{
				dist[u] = dist[v] + d[u];
				pq.push(make_pair(-dist[u], u));
			}
			d[u]--;
		}
	}

	cout << dist[1] << '\n';

	return 0;
}
