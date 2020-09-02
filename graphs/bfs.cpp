#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> adj[N];

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
	vector<bool> visited(n + 1);
	vector<int> level(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	level[1] = 0;
	
	while(!q.empty())
	{
		auto x = q.front();
		q.pop();
		for(int u : adj[x])
		{
			if(visited[u])
			{
				continue;
			}
			visited[u] = true;
			q.push(u);
			level[u] = level[x] + 1;
		}
	}

	
	
	return 0;
}
