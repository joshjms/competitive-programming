
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 1e9 + 7;

int n, q;
vector <int> parent, depth, heavy, head, pos;
int cur_pos;

vector <int> tree, lazy;
vector <int> a, base;

void propagate(int idx, int l, int r) {
	if(l > r) return;
	if(lazy[idx] != 1) {
		(tree[idx] *= lazy[idx]) %= mod;
		if(l < r) {
			(lazy[idx * 2] *= lazy[idx]) %= mod;
			(lazy[idx * 2 + 1] *= lazy[idx]) %= mod;
		}
		lazy[idx] = 1;
	}
}

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = base[l];
		return;
	}
	int mid = (l + r) / 2;
	build(idx * 2, l, mid);
	build(idx * 2 + 1, mid + 1, r);
	tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % mod;
}

void stupd(int idx, int l, int r, int x, int y, int v) {
	propagate(idx, l, r);
	if(l > r || l > y || r < x) return;
	if(l >= x && r <= y) {
		(lazy[idx] *= v) %= mod;
		propagate(idx, l, r);
		return;
	}
	int mid = (l + r) / 2;
	stupd(idx * 2, l, mid, x, y, v);
	stupd(idx * 2 + 1, mid + 1, r, x, y, v);
	tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % mod;
}

int stquery(int idx, int l, int r, int x, int y) {
	propagate(idx, l, r);
	if(l > r || l > y || r < x) return 0;
	if(l >= x && r <= y) {
		return tree[idx];
	}
	int mid = (l + r) / 2;
	return (stquery(idx * 2, l, mid, x, y) + stquery(idx * 2 + 1, mid + 1, r, x, y)) % mod;
}

int dfs(int v, vector<vector<int>> const & adj) {
	int size = 1;
	int max_c_size = 0;
	for(int c : adj[v]) {
		if(c != parent[v]) {
			parent[c] = v, depth[c] = depth[v] + 1;
			int c_size = dfs(c, adj);
			size += c_size;
			if(c_size > max_c_size)
				max_c_size = c_size, heavy[v] = c;
		}
	}
	return size;
}

void decompose(int v, int h, vector<vector<int>> const & adj) {
	head[v] = h, pos[v] = cur_pos++;
	if(heavy[v] != -1)
		decompose(heavy[v], h, adj);
	for(int c : adj[v]) {
		if(c != parent[v] && c != heavy[v])
			decompose(c, c, adj);
	}
}

void init(vector<vector<int>> const & adj) {
	parent = vector<int>(n + 1, 0);
	depth = vector<int>(n + 1, 0);
	heavy = vector<int>(n + 1, -1);
	head = vector<int>(n + 1, 0);
	pos = vector<int>(n + 1, 0);
	cur_pos = 1;

	dfs(1, adj);
	decompose(1, 1, adj);
}

int query(int a, int b) {
    long long res = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = (res + stquery(1, 1, n, pos[head[a]], pos[a])) % mod;
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    if (a != b) res = (res + stquery(1, 1, n, pos[a] + 1, pos[b])) % mod;
    return (int)res;
}

void upd(int a, int b, int x) {
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        stupd(1, 1, n, pos[head[a]], pos[a], x);
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    if (a != b) stupd(1, 1, n, pos[a] + 1, pos[b], x);
}

void someDfs(int cur, int par, vector <vector<pair<int,int>>> const & adj) {
	for(auto i : adj[cur]) if(i.fi != par) {
		a[i.fi] = i.se;
		someDfs(i.fi, cur, adj);
	}
}

void solve() {
	cin >> n >> q;

	a = vector<int>(n + 5, 0);
	base = vector<int>(n + 5, 0);

	vector <vector<int>> g(n + 1, vector<int>());
	vector <vector<pair<int,int>>> gg(n + 1, vector<pair<int,int>>());

	for(int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		g[u].pb(v);
		g[v].pb(u);
		gg[u].pb({v, w});
		gg[v].pb({u, w});
	}

	someDfs(1, -1, gg);
	init(g);

	for(int i = 1; i <= n; i++) {
		base[pos[i]] = a[i];
	}

	tree = vector<int>(4 * n + 5, 0);
	lazy = vector<int>(4 * n + 5, 1);
	build(1, 1, n);

	for(int t = 1; t <= q; t++) {
		int u, v, c; cin >> u >> v >> c;
		upd(u, v, c);
		cout << query(u, v) << "\n";
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
