#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;
const long long INF = 1e18;

vector<pair<int, int>> adj[N];
vector<long long> dist(N, INF);

bool bellman_ford_optimized(int n, int start)
{
	vector<int> cnt(n + 1, 0);
	vector<bool> inqueue(n + 1, false);
	queue<int> q;
	
	dist[start] = 0;
	inqueue[start] = true;
	q.push(start);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		inqueue[v] = false;
		for(auto x : adj[v])
		{
			int u = x.first;
			int cost = x.second;
			if(dist[u] > dist[v] + cost)
			{
				dist[u] = dist[v] + cost;
				if(!inqueue[u])
				{
					inqueue[u] = true;
					q.push(u);
					cnt[u]++;
					if(cnt[u] > n)
						return false;   // negative cycle
				}
			}
		}
	}
	return true;
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
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	
	return 0;
}
