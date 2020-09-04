#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
vector<bool> visited[N];
vectir<int> order;

void dfs(int source)
{
	visited[source] = true;
	for(int u : adj[source])
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
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	toposort(n);
	
	
	return 0;
}
