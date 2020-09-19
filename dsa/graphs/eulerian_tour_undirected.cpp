#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
vector<pair<int, int>> edge;

vector<int> eulerian_undirected(int n)
{
	int start = -1, odddeg = 0;
	// change i to 1 if nodes start from 1
	for(int i = 0; i <= n; i++)
	{
		if(((int) adj[i].size()) & 1)
		{
			odddeg++;
			start = i;
		}
		else if(!adj[i].empty() and start == -1)
		{
			start = i;
		}
	}
	if(odddeg > 2)
	{
		return vector<int>();
	}
	
	// to keep track of the visited edges
	vector<bool> used((int) edge.size(), false); 
	// to keep track of which edge to process
	vector<int> stack, which(n + 1, 0), path;
	
	stack.push_back(start);
	while(!stack.empty())
	{
		int u = stack.back();
		while(which[u] < (int) adj[u].size() and used[adj[u][which[u]]])
		{
			++which[u];
		}
		if(which[u] == (int) adj[u].size())
		{
			stack.pop_back();
			path.push_back(u);
		}
		else
		{
			int ed = adj[u][which[u]];
			used[ed] = 1;
			int to = edge[ed].first == u ? edge[ed].second : edge[ed].first;
			stack.push_back(to);
		}
	}
	// if graph is not connected
	if(count(used.begin(), used.end(), 0))
	{
		return vector<int>();
	}
	return path;
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
		adj[u].push_back((int) edge.size());
		adj[v].push_back((int) edge.size());
		edge.push_back(make_pair(u, v));
	}
	vector<int> path = eulerian_undirected(n);
	
	return 0;
}
