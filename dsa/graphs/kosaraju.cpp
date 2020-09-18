#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N], tadj[N];
vector<int> order, component;
vector<bool> visited(N);

void dfs1(int source)
{
	visited[source] = true;
	for(int u : adj[source])
	{
		if(visited[u] == false)
		{
			dfs1(u);
		}
	}
	order.push_back(source);
}

void dfs2(int source)
{
	visited[source] = true;
	component.push_back(source);
	for(int u : tadj[source])
	{
		if(visited[u] == false)
		{
			dfs2(u);
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
		tadj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == false)
		{
			dfs1(i);
		}
	}
	reverse(order.begin(), order.end());
	visited.assign(n + 1, false);
	for(int i : order)
	{
		if(visited[i] == false)
		{
			component.clear();
			dfs2(i);
			for(int u : component)
			{
				cout << u << " ";
			}
			cout << "\n";
		}
	}
	
	
	
	return 0;
}
