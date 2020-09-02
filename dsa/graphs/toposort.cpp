
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
vector<int> order;

bool toposort(int n)
{
	vector<int> indegree(n + 1);
	for(int i = 1; i <= n; i++)
	{
		for(int u : adj[i])
		{
			indegree[u]++;
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
		}
	}	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		for(int v : adj[u])
		{
			if(--indegree[v] == 0)
			{
				q.push(v);
			}
		}
	}
	
	return ((int) order.size() == n);
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
	}
	
	return 0;
}
