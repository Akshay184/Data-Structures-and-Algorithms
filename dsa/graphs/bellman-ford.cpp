#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;
const long long INF = 1e18;

struct edg 
{
	int from;
	int to;
	int cost;
};

vector<edg> edge;
vector<long long> dist(N, INF);
vector<int> p(N);

bool bellman_ford(int n, int start)
{
	int m = (int) edge.size();
	dist[start] = 0;
	int last = -1;
	for(int i = 0; i < n - 1; i++)
	{
		last = -1;
		bool operation = false;
		for(int j = 0; j < m; j++)
		{
			if(dist[edge[j].to] > dist[edge[j].from] + edge[j].cost)
			{
				// to prevent overflow
				dist[edge[j].to] = max(-INF, dist[edge[j].from] + edge[j].cost);
				p[edge[j].to] = edge[j].from;
				last = edge[j].to;
				operation = true;
			}
		}
		if(operation == false)
			break;
	}
	if(last == -1)
	{
		return false;
	}
	for(int i = 0; i < n - 1; i++)
	{
		bool operation = false;
		for(int j = 0; j < m; j++)
		{
			if(dist[edge[j].to] > dist[edge[j].from] + edge[j].cost)
			{
				// to prevent overflow
				dist[edge[j].to] = -INF;
				p[edge[j].to] = edge[j].from;
				operation = true;
			}gir
		}
		if(!operation)
			break;
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
	edge.resize(m);
	for(int i = 0; i < m; i++)
	{
		cin >> edge[i].from >> edge[i].to >> edge[i].cost;
	}
	int start;
	cin >> start;
	bool cycle = bellman_ford(n, start);
	cout << cycle << "\n";
	
	return 0;
}
