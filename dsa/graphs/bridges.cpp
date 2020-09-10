#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
vector<bool> visited(N);
vector<int> tin(N), low(N);
int timer;

void dfs(int source, int parent = -1)
{
	visited[source] = true;
	tin[source] = low[source] = ++timer;
	for(int u : adj[source])
	{
		if(u == parent)
		{
			continue;
		}
		if(visited[u])
		{
			low[source] = min(low[source], tin[u]);
		}
		else
		{
			dfs(u, source);
			low[source] = min(low[source], low[u]);
			if(low[u] > low[source])
			{
				cout << "bridge " << source << " to " << u << "\n";
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	
	return 0;
}
