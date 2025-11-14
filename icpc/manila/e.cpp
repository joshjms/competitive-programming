
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
	int n, m, p, l; cin >> n >> m >> p >> l;

	struct Edge {
		int u, v;
		vector <int> p;
		unordered_map <int, int> par;
		bool valid = true;

		Edge(int _u, int _v) {
			u = _u;
			v = _v;
			p = vector <int> ();
		}

		int getDest(int src) {
			return (src == u) ? v : (src == v) ? u : -1;
		}

		int find(int u) {
			if(!par.count(u)) return u;
			if(par[u] == u) return u;
			return par[u] = find(par[u]);
		}

		int join(int u, int v) {
			u = find(u);
			v = find(v);
			if(u == v) return 0;
			par[u] = v;
			return 1;
		}

		void setInvalid() {
			valid = false;
		}
	};

	vector <Edge *> edges;
	vector <vector<Edge *>> g(n + 1);
	unordered_map <int, Edge *> mp;

	auto makeKey = [&](int a, int b) {
		return (a << 32) ^ b;
	};
	
	for(int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		Edge * e = new Edge(u, v);
		g[u].pb(e);
		g[v].pb(e);
		mp[makeKey(u, v)] = e;
		mp[makeKey(v, u)] = e;
		edges.pb(e);
	}

	for(int i = 1; i <= p; i++) {
		vector <int> path;
		for(int j = 1; j <= l; j++) {
			int u; cin >> u;
			path.pb(u);
		}

		for(int i = 0; i < l; i++) {
			int u = path[i];
			int v = path[(i + 1) % l];
			Edge * e = mp[makeKey(u, v)];
			e -> p.pb(i);
		}
	}

	for(int i = 0; i < edges.size(); i++) {
		vector <int> &A = edges[i] -> p;
		sort(A.begin(), A.end());
		A.erase(unique(A.begin(), A.end()), A.end());

		if(A.size() == 0) continue;

		if(A.size() >= l) {
			edges[i] -> setInvalid();
			continue;
		}

		for(int j = 0; j < A.size(); j++) {
			edges[i] -> join(A[j], (A[j] + 1) % l);
		}
	}

	int a, b; cin >> a >> b;
	vector <int> dist(n + 1, 1e18);

	dist[a] = 0;
	priority_queue <pair<int,int>> pq;
	pq.push({0, a});

	while(!pq.empty()) {
		pair <int,int> p = pq.top();
		pq.pop();

		int cur = p.se;
		int d = -p.fi;

		if(d > dist[cur]) continue;

		for(int i = 0; i < g[cur].size(); i++) {
			Edge * e = g[cur][i];

			if(!(e -> valid)) continue;

			int target = e -> getDest(cur);
			int ne = e -> find(d % l);
			int wait = (ne - (d % l) + l) % l;

			// debug(cur);
			// debug(target);
			// debug(ne);
			// debug(wait);

			if(dist[target] > d + wait + 1) {
				dist[target] = d + wait + 1;
				pq.push({-(d + wait + 1), target});
			}
		}
	}

	if(dist[b] >= 1e18) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	cout << dist[b] << "\n";
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
