#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 17;

int d[N][N];
int dp[N][1 << N];
int n;

// pos stores current positon and mask contains the value for the visited cities
// if city is visited bit is 1 else bit is 0
// time complexity = O(n2 * 2^n)
int solve(int pos, int mask)
{
	if(mask == (1 << n) - 1)
	{
		return d[pos][0];
	}
	if(dp[pos][mask] != -1)
	{
		return dp[pos][mask];
	}
	int sol = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		if((mask & (1 << i)) == 0)
		{
			sol = min(sol, solve(i, mask | (1 << i)) + d[pos][i]);
		}
	} 
	return dp[pos][mask] = sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> d[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1);

	return 0;
}
