
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
	vector <vector<int>> g(n + 5);

	vector <int> in(n + 5, 0), out(n + 5, 0);
	vector <pair<pair<int,int>, int>> edges;

	struct Node {
		int par, sz = 0;
	};

	int ans = 0;

	for(int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		ans += w;

		if(u == v) continue;

		g[u].pb(v);
		g[v].pb(u);
		in[u]++, in[v]++;
		out[u]++, out[v]++;
		edges.pb({{u, v}, w});
	}
	
	vector <Node> dsu(n + 5);
	for(int i = 1; i <= n; i++) {
		dsu[i].par = i;
		if(g[i].size() % 2) {
			// debug(i);
			dsu[i].sz = 1;
		}
	}

	function<int(int)> find = [&](int u) {
		return dsu[u].par == u ? u : (dsu[u].par = find(dsu[u].par));
	};

	priority_queue <int> pq;
	int cap = 0;

	auto join = [&](int u, int v, int w) -> long long {
		u = find(u);
		v = find(v);
		if (u == v) return 0ll;
		int ret = ((dsu[u].sz % 2) && (dsu[v].sz % 2));
		dsu[v].par = u;
		dsu[u].sz += dsu[v].sz;
		if (ret) {
			pq.push(w);
		}
		return ret;
	};

	for(int e = 0; e < edges.size(); e++) {
		int u = edges[e].fi.fi;
		int v = edges[e].fi.se;
		int w = edges[e].se;
		if(u != v) cap += join(u, v, w);
		while(pq.size() > cap) pq.pop();
	}

	while(!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans << "\n";
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
