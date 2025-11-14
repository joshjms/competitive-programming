
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
	int n, k, m; cin >> n >> k >> m;

	vector <vector<int>> cap(n + 5, vector<int>(k + 5));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < k; j++) {
			cin >> cap[i][j];
		}
	}
	
	vector <vector<int>> adj_mask(n + 5, vector<int>(k + 5, 0));
	for(int i = 1; i <= m; i++) {
		int f, u, v; cin >> f >> u >> v;
		u--, v--;
		adj_mask[f][u] |= (1ll << v);
	}

	// define dp[floor][mask] to be the minimum cost to make ONLY the nodes at the mask reachable
	vector <int> prev_dp((1ll << k), 2e9);
	for(int i = 1; i <= n; i++) {
		vector <int> cur_dp((1ll << k), 2e9);

		if(i > 1) {
			vector <bool> vis(k, 0);
			for(int prev_mask = 0; prev_mask < (1ll << k); prev_mask++) {
				int cur_mask = 0;
				for(int room = 0; room < k; room++) if(prev_mask & (1ll << room)) 
					cur_mask |= adj_mask[i - 1][room];
				cur_dp[cur_mask] = min(cur_dp[cur_mask], prev_dp[prev_mask]);
			}
		}

		for(int j = 0; j < (1ll << k); j++)
			cout << cur_dp[j] << " ";
		cout << "\n";

		cur_dp[(1ll << k) - 1] = 0;
		for(int mask = (1ll << k) - 2; mask >= 0; mask--) {
			for(int room = 0; room < k; room++) if(!(mask & (1ll << room))) {
				cur_dp[mask] =  min(cur_dp[mask], cur_dp[mask ^ (1ll << room)] + cap[i][room]);
			}
		}

		for(int j = 0; j < (1ll << k); j++)
			cout << cur_dp[j] << " ";
		cout << "\n";

		cout << cur_dp[0] << "\n";

		prev_dp = move(cur_dp);
	}
	
	cout << "\n";
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
