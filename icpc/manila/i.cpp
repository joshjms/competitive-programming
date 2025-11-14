
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
	// code here
	int n, m;
	cin >> n >> m;
	vector<int> raw, cnt(m, -1), adj[m];
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x) {
			for (int j = 0; j < x; j++) {
				int u;
				cin >> u;
				u--;
				adj[i].pb(u);
			}
		}
		else {
			raw.pb(i);
			cin >> cnt[i];
		}
	}
	unordered_map<int, int> need[n];
	// function<void(int, int)> prop = [&](int u, int s) {
	// 	if (cnt[u] != -1) {
	// 		need[s][u]++;
	// 		return;
	// 	}
	// 	for (auto v : adj[u]) prop(v, s);
	// };
	for (int s = 0; s < n; s++) {
		// prop(i, i);
		need[s][s] = 1;
		for (int i = s; i < m; i++) {
			for (auto j : adj[i]) need[s][j] = min(need[s][j] + need[s][i], 1000000000ll);
		}
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		unordered_map<int, int> mp;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				for (int k : raw) mp[k] = min(mp[k] + need[j][k], 1000000000ll);
			}
		}
		// for (int k : raw) cout << mp[k] << " ";
		// cout << '\n';
		bool can = true;
		for (int k : raw) if (mp[k] > cnt[k]) can = false;
		if (can) ans = max(ans, 1ll * __builtin_popcount(i));
	}
	cout << ans;
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
