#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
vector<int> tin(N), low(N);
vector<bool> visited(N);
int timer = 0;

void dfs(int source, int parent = -1)
{
	int children = 0;
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
			children++;
			low[source] = min(low[source], low[u]);
			if(low[u] >= tin[source] and parent != -1)
			{
				cout << "Articuation point " << source << "\n";
			}
		}
	}
	if(parent == -1 and children > 1)
	{
		cout << "Articulation point " << source << "\n";
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
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	
	return 0;
}
