
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve(int tc) {
	int n; cin >> n;
	vector <int> a(n + 5, 0);

	vector <pair<int,pair<int,int>>> v;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		v.pb({a[i], {0, i}});
	}

	for(int i = 1; i < n; i++) {
		v.pb({abs(a[i] - a[i + 1]), {i, i + 1}});
	}

	sort(v.begin(), v.end());
	vector <int> par(n + 5, 0);
	for(int i = 0; i <= n; i++)
		par[i] = i;

	function <int(int)> find = [&](int u) {
		if(par[u] == u) return u;
		return par[u] = find(par[u]);
	};

	auto join = [&](int u, int v) {
		u = find(u);
		v = find(v);

		if(u == v) return 0;

		par[u] = v;
		return 1;
	};

	int ans = 0;
	for(int i = 0; i < v.size(); i++) {
		if(join(v[i].se.fi, v[i].se.se)) {
			ans = max(ans, v[i].fi);
		}
	}

	cout << "Case #" << tc << ": " << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
