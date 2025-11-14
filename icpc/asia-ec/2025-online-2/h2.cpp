
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;

	vector <int> g[n + 1];
	queue <pair<pair<int,int>, int>> q;
	int dp[n + 1][n + 1];
	bool vis[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));

	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;

		g[u].pb(v);
		g[v].pb(u);

		q.push({{u, v}, 1});
		vis[u][v] = 1;
		vis[v][u] = 1;

		dp[u][v] = 1;
	}

	while(!q.empty()) {
		int u = q.front().fi.fi;
		int v = q.front().fi.se;
		int d = q.front().se;

		q.pop();

		for(auto i : g[u]) {
			if(!vis[i][u] && !vis[u][i]) {
				vis[i][u] = 1;
				vis[u][i] = 1;
				dp[i][u] = dp[u][v] * d;
			}
		}
	}

}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
