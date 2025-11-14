
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
	int n, q;
	cin >> n >> q;

	vector <int> g[n + 1];

	vector <int> a(n + 5, 0), par(n + 5, 0);
	for(int i = 1; i <= n; i++) 
		cin >> a[i];

	for(int i = 2; i <= n; i++) {
		cin >> par[i];
		g[par[i]].pb(i);
	}

	vector <int> sum(n + 5, 0);

	function <void(int)> dfs = [&](int u) {
		sum[u] += a[u];
		for(auto v : g[u]) {
			dfs(v);
			sum[u] += sum[v];
		}
	};

	dfs(1);

	vector <pair<pair<int,int>,int>> queries;

	for(int T = 1; T <= q; T++) {
		int l, r; cin >> l >> r;
		queries.pb({{l, r}, T});
	}

	int k = sqrt(n);
	sort(queries.begin(), queries.end(), [&](auto a, auto b) {
		int aa = a.fi.fi / k;
		int bb = b.fi.fi / k;
		if(aa == bb) return aa & 1 ? a.fi.se < b.fi.se : a.fi.se > b.fi.se;
		return aa < bb;
	});

	vector <int> ps(n + 5, 0);
	for(int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + sum[i];
	}

	// for(int i = 1; i <= n; i++)
	// 	cout << sum[i] << " ";
	// cout << "\n";

	int ml = 1, mr = 0, s = 0;
	int childs[n + 5];
	memset(childs, 0, sizeof(childs));

	auto add = [&](int idx) {
		if(par[idx] >= ml && par[idx] <= mr) {
			s += sum[idx];
		}
		childs[par[idx]] += sum[idx];
		s += childs[idx];
	};

	auto rem = [&](int idx) {
		if(par[idx] >= ml && par[idx] <= mr) {
			s -= sum[idx];
		}
		s -= childs[idx];
		childs[par[idx]] -= sum[idx];
	};

	vector <int> ans(q + 5, 0);

	for(auto q : queries) {
		int l = q.fi.fi;
		int r = q.fi.se;
		int i = q.se;

		while(ml > l) {
			add(ml - 1);
			ml--;
		}
		while(mr < r) {
			add(mr + 1);
			mr++;
		}
		while(ml < l) {
			rem(ml);
			ml++;
		}
		while(mr > r) {
			rem(mr);
			mr--;
		}

		ans[i] = ps[r] - ps[l - 1] - s;
	}

	for(int i = 1; i <= q; i++)
		cout << ans[i] << "\n";
	
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
