
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
	int n, m; cin >> n >> m;
	vector <int> g[n + 5];
	
	for(int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	queue <int> q;
	bool vis[n + 5];
	memset(vis, 0, sizeof(vis));

	q.push(1);
	vis[1] = true;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for(auto nb : g[cur]) if(!vis[nb]) {
			vis[nb] = 1;
			q.push(nb);
		}
	}

	cout << "\n";
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
