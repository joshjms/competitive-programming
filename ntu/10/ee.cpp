
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
	int n, k; cin >> n >> k;

	vector <int> g[n + 5];
	vector <vector<vector<int>>> paths (n + 5, vector<vector<int>>(n + 5));
	vector <vector<int>> dist(n + 5, vector<int>(n + 5, 0));

	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	vector <bool> vis(n + 5, 0);
	vector <int> tmp;

	function <void(int, int)> dfs = [&](int cur, int src) {
		tmp.pb(cur);
		int u = min(cur, src);
		int v = max(cur, src);

		paths[u][v] = tmp;

		for(auto i : g[cur]) if(!vis[i]) {
			dist[src][i] = dist[src][cur] + 1;
			dist[i][src] = dist[src][cur] + 1;
			dfs(i, src);
		}

		tmp.pop_back();
	};

	for(int i = 1; i <= n; i++) {
		vis.assign(n + 5, 0);
		vis[i] = 1;
		dfs(i, i);
	}

	vector <vector<vector<int>>> adjDist(n + 5, vector<vector<int>>(n + 5));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			adjDist[i][dist[i][j]].pb(j);
		}
	}

	vis.assign(n + 5, 0);

	queue <int> q;
	q.push(1);
	vis[1] = 1;

	vector <pair<int,int>> queries;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto nb : adjDist[u][k + 1]) if(!vis[nb]) {
			int v = nb;
			int u2, v2;

			for(auto nb2 : adjDist[u][k]) {
				if(dist[u][nb2] == k && dist[nb2][v] == 1) {
					v2 = nb2;
					break;
				}
			}

			for(auto nb2 : adjDist[v][k]) {
				if(dist[u][nb2] == 1 && dist[v][nb2] == k) {
					u2 = nb2;
					break;
				}
			}

			queries.pb({u, v2});
			queries.pb({u2, v});
		}

		
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
