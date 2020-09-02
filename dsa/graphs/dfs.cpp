#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> adj[N];

void dfs(int source, int parent = -1)
{
	for(int u : adj[source])
	{
		if(u == parent)
		{
			continue;
		}
		dfs(u, source);
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	
	return 0;
}
