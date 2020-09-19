#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
vector<int> indegree(N), outdegree(N);
vector<int> path;
int n, m;


bool is_path()
{
	int startnode = -1;
	int endnode = -1;
	for(int i = 1; i <= n; i++)
	{
		if(indegree[i] == outdegree[i])
		{
			continue;
		}
		int x = indegree[i] - outdegree[i];
		if(abs(x) > 1)
		{
			// violation of condition for eulerian_path
			// change if graph is directed!!
			return false;
		}
		if(x == 1 and endnode == -1)
		{
			endnode = i;
		}
		else if(x == - 1 and startnode == -1)
		{
			startnode = i;
		}
		else
		{
			return false;
		}
	}
	return ((endnode == -1 and startnode == -1) || (endnode != -1 and startnode != -1));
}

int startNode()
{
	int first = 1;
	for(int i = 1; i <= n; i++)
	{
		if(outdegree[i] - indegree[i] == 1)
		{
			return i;
		}
		if(outdegree[i] > 0)
			first = i;
	}
	return first;
}

void dfs(int u)
{
	while(outdegree[u] != 0)
	{
		int next = adj[u][--outdegree[u]];
		dfs(next);
	}
	path.push_back(u);
}

bool eulerian_path()
{
	// counting the indegree and outdegree of every vertex
	for(int i = 1; i <= n; i++)
	{
		for(int u : adj[i])
		{
			indegree[u]++;
			outdegree[i]++;
		}
	}
	
	// if there is no edge in graph return null
	if(m == 0)
	{
		return false;
	}
	
	// if there is no path
	if(!is_path())
	{
		return false;
	}
	
	// starting node of the euler tour
	int first = startNode();
	
	dfs(first);
	
	// graph must be connected but it can have singlton nodes
	if((int) path.size() != m + 1)
	{
		return false;
	}
	
	return true;
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	//int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		// change this in case of undirected edges!!
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	bool sol = eulerian_path();
	if(sol)
	{
		for(auto i : path)
		{
			cout << i << " ";
		}
	}
	
	return 0;
}
