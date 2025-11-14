
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int f[3004];

void solve() {
	// code here
	int n;
	cin >> n;
	vector<int> adj[n];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<vector<int>> p(n, vector<int>(20, -1));
	vector<int> lv(n), leaf;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 1) {
			leaf.pb(i);
		}
	}
	function<void(int, int)> dfs = [&](int u, int par) {
		for (auto v : adj[u]) {
			if (v == par) continue;
			lv[v] = lv[u] + 1;
			p[v][0] = u;
			dfs(v, u);
		}
	};
	dfs(0, -1);
	for (int j = 1; j < 20; j++) {
		for (int i = 0; i < n; i++) {
			if (p[i][j - 1] != -1)
				p[i][j] = p[p[i][j - 1]][j - 1];
			else
				p[i][j] = -1;
		}
	}
	auto lca = [&](int u, int v) {
		if (lv[u] < lv[v]) swap(u, v);
		int diff = lv[u] - lv[v];
		for (int i = 0; i < 20; i++) {
			if ((diff >> i) & 1) {
				u = p[u][i];
			}
		}
		if (u == v) return u;
		for (int i = 19; i >= 0; i--) {
			if (p[u][i] != p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		}
		return p[u][0];
	};
	int ans = 1;
	// for (int i : leaf) {
	// 	for (int j : leaf) {
	// 		if (i >= j) continue;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int x = lca(i, j);
			int k = lv[i] + lv[j] - 2 * lv[x] + 1;
			ans = (ans + f[k]) % mod;
			ans = (ans + 3 * mod - 2 * f[k - 1]) % mod;
			(ans += (f[k - 2]) % mod) %= mod;
			// ans = (ans + f[k] - 1) % mod;
			// if (x != i && x != j) ans = (ans - f[lv[i] - lv[x] - 1] - f[lv[j] - lv[x] - 1]) % mod;
			// cout << i+1 << " " << j+1 << " " <<x+1<<" "<< k << " f=" << 2 * f[k - 1] % mod - f[k - 2] << " " << ans << "\n";
		}
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	f[0] = 1;
	for (int i = 1; i <= 3000; i++) f[i] = f[i - 1] * i % mod;
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
