
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
	vector<pair<int, int>> adj[n];
	bool mat[n][n];
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		mat[u][v] = 1;
		mat[v][u] = 1;
	}
	int s1, t1, s2, t2;
	cin >> s1 >> t1 >> s2 >> t2;
	s1--; t1--;
	s2--; t2--;
	vector<int> dis(n, INT_MAX);
	struct A {
		int d, u;
		bool operator <(const A &o) const {
			return d > o.d;
		}
	};
	priority_queue<A> pq;
	pq.push({dis[s1] = 0, s1});
	// vector<vector<bitset<24>>> com1(n + 1), com2(n + 1);
	// bitset <24> start1;
	// start1.set(s1);
	// com1[s1].pb(start1);
	// bitset <24> start2;
	// start2.set(s2);
	// com2[s2].pb(start2);
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (dis[u] != d) continue;
		for (auto [v, w] : adj[u]) {
			if (dis[v] > d + w) {
				// com1[v].clear();
				// for(auto x : com1[u]) {
				// 	bitset <24> y = x;
				// 	y.set(v);
				// 	com1[v].pb(y);
				// }
				pq.push({dis[v] = d + w, v});
			}
			// else if (dis[v] == d + w) {
			// 	for(auto x : com1[u]) {
			// 		bitset <24> y = x;
			// 		y.set(v);
			// 		com1[v].pb(y);
			// 	}
			// }
		}
	}
	int shortest1 = dis[t1];
	dis.assign(n, INT_MAX);
	pq.push({dis[s2] = 0, s2});
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (dis[u] != d) continue;
		for (auto [v, w] : adj[u]) {
			if (dis[v] > d + w) {
				// com2[v].clear();
				// for(auto x : com2[u]) {
				// 	bitset <24> y = x;
				// 	y.set(v);
				// 	com2[v].pb(y);
				// }
				pq.push({dis[v] = d + w, v});
			}
			// else if (dis[v] == d + w) {
			// 	for(auto x : com2[u]) {
			// 		bitset <24> y = x;
			// 		y.set(v);
			// 		com2[v].pb(y);
			// 	}
			// }
		}
	}
	int shortest2 = dis[t2];


	vector<int> sos(1 << n);
	vector<vector<int>> dp(1 << n, vector<int>(n + 1));

	for (int x = 0; x < (1 << n); x++) {
		if(!(x & (1ll << s1)) || !(x & (1ll << t1))) continue;
		if((x & (1ll << s2)) || (x & (1ll << t2))) continue;
		queue<int> q;
		vector<bool> vis(n);
		q.push(s1);
		bool can = true;
		int dist;
		// debug(x);
		while (!q.empty()) {
			auto u = q.front();
			// debug(u);
			q.pop();
			vis[u] = true;
			if (u == t1) break;
			int cnt = 0;
			for (auto [v, w] : adj[u]) {
				if ((x & (1ll << v)) && !vis[v]) {
					// debug(v);
					dist += w;
					q.push(v);
					cnt++;
				}
			}
			// debug(
			if (cnt != 1) {
				can = false;
				break;
			}
		}
		if (can && dist == shortest1) dp[x][0]++;
	}

	// for(auto i : com1[t1])
	// 	cout << i << "\n";
	
	// for(auto i : com2)
	// 	cout << i << "\n";


	// for (auto i : com1[t1]) {
	// 	int val = i.to_ullong();
	// 	dp[val][0]++;
	// }

	for (int x = 0; x < (1 << n); x++) {
		if(!(x & (1ll << s1)) || !(x & (1ll << t1))) continue;
		if((x & (1ll << s2)) || (x & (1ll << t2))) continue;
		for (int i = 0; i < n; i++) {
			dp[x][i + 1] = dp[x][i];
			if (x & (1 << i)) { dp[x][i + 1] += dp[x ^ (1 << i)][i]; }
		}
		sos[x] = dp[x][n];
	}

	int ans = 0;

	for (int x = 0; x < (1 << n); x++) {
		if((x & (1ll << s1)) || (x & (1ll << t1))) continue;
		if(!(x & (1ll << s2)) || !(x & (1ll << t2))) continue;
		queue<int> q;
		vector<bool> vis(n);
		q.push(s2);
		bool can = true;
		int dist;
		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			vis[u] = true;
			if (u == t2) break;
			int cnt = 0;
			for (auto [v, w] : adj[u]) {
				if ((x >> v & 1) && !vis[v]) {
					dist += w;
					q.push(v);
					cnt++;
				}
			}
			if (cnt != 1) {
				can = false;
				break;
			}
		}
		if (can && dist == shortest2) {
			int val = x;
			val ^= (1ll << n) - 1;
			ans += sos[val];
		}
	}

	// for(auto i : com2[t2]) {
	// 	int val = i.to_ullong();
	// 	val ^= (1ll << n) - 1;
	// 	ans += sos[val];
	// }

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
