
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
	vector <pair<int,pair<int,int>>> e(m + 5, {0, {0, 0}});

	for(int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		e[i] = {w, {u, v}};
	}

	sort(e.begin() + 1, e.begin() + m + 1);

	vector <vector<int>> pt;

	for(int l = 1; l <= m; l++) {
		for(int r = l; r <= m; r++) {
			int par[n + 5];
			for(int i = 1; i <= n; i++)
				par[i] = i;

			function <int(int)> find = [&](int u) {
				while (par[u] != u) {
					par[u] = par[par[u]]; 
					u = par[u]; 
				}
				return u;
			};

			function <int(int,int)> join = [&](int u, int v) {
				u = find(u);
				v = find(v);
				if(u == v) return 0ll;
				par[u] = v;
				return 1ll;
			};

			vector <int> conns;

			for(int i = l; i <= r; i++) {
				if(join(e[i].se.fi, e[i].se.se)) {
					conns.pb(i);
				}
			}

			if(conns.size() == n - 1) {
				pt.pb(conns);
				break;
			}
		}
	}

	int spantrees = pt.size();
	vector <vector<int>> ps(spantrees, vector<int>(n + 5, 0));

	for(int i = 0; i < pt.size(); i++) {
		for(int j = 0; j < pt[i].size(); j++) {
			ps[i][j + 1] = ps[i][j] + e[pt[i][j]].fi;
			cout << ps[i][j + 1] << " ";
		}
		cout << "\n";
	}

	int p, k, a, b, c; cin >> p >> k >> a >> b >> c;
	vector <pair<int,int>> q(k + 5, {0, 0});

	int ans = 0, cur = -1;

	for(int i = 1; i <= p; i++) {
		cin >> q[i].fi;
		q[i].se = i;
	}

	for(int i = p + 1; i <= k; i++) {
		q[i].fi = (q[i - 1].fi * a + b) % c;
		q[i].se = i;
	}

	sort(q.begin() + 1, q.begin() + k + 1);

	function <int(int, int)> getCost = [&](int idx, int x) {
		assert(pt[idx].size() == n - 1);
		int l = 0;
		int r = n - 2;
		int ans = -1;

		while(l <= r) {
			int mid = (l + r) / 2;
			if(e[pt[idx][mid]].fi <= x) {
				l = mid + 1;
				ans = mid;
			} else {
				r = mid - 1;
			}
		}

		int leftSeg = ps[idx][ans + 1];
		int leftElms = ans + 1;

		int rightSeg = ps[idx][n - 1] - ps[idx][ans + 1];
		int rightElms = (n - 1) - (leftElms);

		int cost = x * leftElms - leftSeg + rightSeg - x * rightElms;

		return cost;
	};

	int pts = pt.size();

	int idx = -1;
	for(int i = 1; i <= k; i++) {
		int Q = q[i].fi;
		while(idx < pts - 1 && (idx == -1 || getCost(idx, Q) > getCost(idx + 1, Q))) {
			idx++;
		}
		int c = getCost(idx, Q);
		debug(Q);
		debug(c);
		ans ^= c;
	}

	cout << ans << "\n";
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
