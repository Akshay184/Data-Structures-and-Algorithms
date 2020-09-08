#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

using pii = pair<int, int>;

const int N = 2e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> adj[N];
vector<int> dist(N, INF);
vector<int> p(N);

void dijkstra(int start, int n)
{
	dist[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, start});
	while(!q.empty())
	{
		auto x = q.top();
		q.pop();
		int d = x.first;
		int v = x.second;
		if(dist[v] != d)
			continue;
		for(auto u : adj[v])
		{
			int to = u.first;
			int len = u.second;
			if(dist[v] + len < dist[to])
			{
				dist[to] = dist[v] + len;
				p[to] = v; 	
				q.push({dist[to], to});
			}
		}
	}
}

vector<int> dijkstra_path(int start, int end)
{
	vector<int> path;
	for(int v = end; v != start; v = p[v])
	{
		path.push_back(v);
	}
	path.push_back(start);
	reverse(path.begin(), path.end());
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
		// change according to type of graph!
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int start, end;
	cin >> start >> end;
	dijkstra(start, n);
	
	
	return 0;
}
