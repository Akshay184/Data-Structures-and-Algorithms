#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> adj[N];
vector<bool> visited(N);
vector<int> order;


void dfs(int source)
{
	visited[source] = true;
	for(auto [u, v] : adj[source])
	{
		if(visited[u])
		{
			continue;
		}
		dfs(u);
	}
	order.push_back(source);
}

void toposort(int n)
{
	visited.assign(n, false);
	order.clear();
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
}

vector<int> SSSP(int n)
{
	vector<int> length(n + 1, INF);
	length[*order.begin()] = 0;
	for(auto i : order)
	{
		for(auto [u, w] : adj[i])
		{
			length[u] = min(length[u], length[i] + w);
		}
	}
	return length;
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
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
	}
	// toposort for DAG to get the topological ordering
	toposort(n);
	
	// appling SSSP
	vector<int> length = SSSP(n);
	
	for(int i = 1; i <= n; i++)
	{
		cout << length[i] << " ";
	}
	
	
	
	return 0;
}
