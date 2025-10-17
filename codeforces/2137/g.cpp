
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
	int n, m, q;
	cin >> n >> m >> q;

	vector <int> g[n + 1], rg[n + 1];
	for(int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		rg[v].pb(u);
	}

	bool willWin[n + 1];
	memset(willWin, 0, sizeof(willWin));

	int cnt[n + 1];
	memset(cnt, 0, sizeof(cnt));

	bool vis[n + 1];
	memset(vis, 0, sizeof(vis));

	auto bfs = [&](int U) {
		queue <int> q;
		q.push(U);

		while(!q.empty()) {
			int u = q.front();
			q.pop();

			vis[u] = 1;
			willWin[u] = 1;

			for(auto ne : rg[u]) if(!vis[ne]) {
				cnt[ne]++;
				if(cnt[ne] == g[ne].size()) {
					q.push(ne);
				}
			}
		}
	};

	for(int i = 1, x, u; i <= q; i++) {
		cin >> x >> u;
		switch (x) {
		case 1:
			bfs(u);
			break;
		case 2:
			cout << willWin[u] << "\n";
			break;
		default:
			break;
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
