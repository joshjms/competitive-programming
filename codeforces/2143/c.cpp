
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n;
vector <pair<pair<int,int>, pair<int,int>>> edges;

int par[200005];

int find(int u) {
	if(par[u] == u) return u;
	return par[u] = find(par[u]);
}

int join(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v) return 0;
	par[v] = u;
	return 1;
}

vector <int> g[200005];
int rg[200005];
int ctr, ans[200005];
bool vis[200005];

void dfs(int u) {
	vis[u] = 1;
	for(auto c : g[u]) if(!vis[c]) {
		dfs(c);
	}
	ans[u] = ++ctr;
}

void solve() {
	cin >> n;
	edges.clear();

	for(int i = 1; i < n; i++) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		edges.pb({{u, v}, {x, y}});
	}

	vector <pair<int, pair<pair<int,int>, pair<int,int>>>> v;
	for(int i = 0; i < n - 1; i++) {
		v.pb({abs(edges[i].se.fi - edges[i].se.se), edges[i]});
	}
	sort(v.begin(), v.end());

	// for(auto i : v) {
	// 	if(i.se.se.fi > i.se.se.se) {
	// 		cout << i.se.fi.fi << ">" << i.se.fi.se << "\n";
	// 	} else {
	// 		cout << i.se.fi.se << ">" << i.se.fi.fi << "\n";
	// 	}
	// }

	for(int i = 1; i <= n; i++)
		g[i].clear();

	for(int i = 1; i <= n; i++)
		par[i] = i;

	for(int i = 1; i <= n; i++) {
		rg[i] = 0;
		vis[i] = 0;
	}

	for(auto i : v) {
		if(i.se.se.fi > i.se.se.se) {
			if(join(i.se.fi.fi, i.se.fi.se)) {
				g[i.se.fi.fi].pb(i.se.fi.se);
				rg[i.se.fi.se]++;
			}
		} else {
			if(join(i.se.fi.se, i.se.fi.fi)) {
				g[i.se.fi.se].pb(i.se.fi.fi);
				rg[i.se.fi.fi]++;
			}
		}
	}

	// for(int i = 1; i <= n; i++) {
	// 	for(auto j : g[i])
	// 		cout << j << " ";
	// 	cout << "\n";
	// }
	
	ctr = 0;

	int root = -1;
	for(int i = 1; i <= n; i++) {
		if(rg[i] == 0) {
			dfs(i);
		}
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << "\n";
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
