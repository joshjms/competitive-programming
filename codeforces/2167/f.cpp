
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
	int n, k; cin >> n >> k;
	vector <int> g[n + 5];

	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	vector <int> cnt(n + 5, 0), depth(n + 5, 0);
	vector <vector<int>> p(n + 5, vector<int>(20, -1));

	function <void(int, int)> dfs = [&](int cur, int par) {
		cnt[cur]++;

		p[cur][0] = par;
		for(int i = 1; i < 20; i++) {
			if(p[cur][i - 1] == -1) break;
			p[cur][i] = p[p[cur][i - 1]][i - 1];
		}

		for(auto i : g[cur]) if(i != par) {
			depth[i] = depth[cur] + 1;
			dfs(i, cur);
			cnt[cur] += cnt[i];
		}
	};

	dfs(1, -1);

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		ans++;
		
		if(cnt[i] >= k) {
			ans += n - cnt[i];
		}

		if(n - cnt[i] < k) continue;

		int P = i;
		for(int j = 19; j >= 0; j--) {
			int pp = p[P][j];
			if(pp == -1) continue;
			int ppp = p[pp][0];
			if(ppp == -1) continue;

			if(n - cnt[pp] >= k) {
				P = pp;
			}
		}

		ans += depth[i] - depth[p[P][0]];
	}

	cout << ans << "\n";
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
