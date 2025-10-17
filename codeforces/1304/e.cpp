
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
	int n; cin >> n;
	vector <vector<int>> g(n + 1);

	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	vector <vector<int>> par(n + 1, vector<int>(20, -1));
	vector <int> depth(n + 1, 0);
	
	function <void(int, int)> getParents = [&](int u, int p) {
		depth[u] = (p == -1 ? 0 : depth[p] + 1);

		par[u][0] = p;
		for(int j = 1; j < 20; j++) {
			par[u][j] = (par[u][j - 1] == -1 ? -1 : par[par[u][j - 1]][j - 1]);
		}

		for(auto i : g[u]) if(i != p) {
			getParents(i, u);
		}
	};

	getParents(1, -1);

	function<int(int, int)> lca = [&](int u, int v) {
		if(depth[u] < depth[v]) swap(u, v);

		for(int i = 19; i >= 0; i--) {
			if(par[u][i] != -1 && depth[par[u][i]] >= depth[v])
				u = par[u][i];
		}

		if(u == v) return u;

		for(int i = 19; i >= 0; i--) {
			if(par[u][i] != par[v][i]) {
				u = par[u][i];
				v = par[v][i];
			}
		}

		return par[u][0];
	};

	function <int(int, int)> getDist = [&](int u, int v) {
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	};

	int q; cin >> q;
	for(int t = 1; t <= q; t++) {
		int x, y, a, b, k; cin >> x >> y >> a >> b >> k;

		int distUsingTree = getDist(a, b);
		int distUsingExtraEdge = min(getDist(a, x) + 1ll + getDist(y, b), getDist(a, y) + 1ll + getDist(x, b));
	
		if(min(distUsingTree, distUsingExtraEdge) > k) {
			cout << "NO\n";
			continue;
		}

		if(k >= distUsingTree) {
			if(k % 2 == distUsingTree % 2) {
				cout << "YES\n";
				continue;
			}
		}

		if(k >= distUsingExtraEdge)  {
			if(k % 2 == distUsingExtraEdge % 2) {
				cout << "YES\n";
				continue;
			}
		}

		cout << "NO\n";
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
