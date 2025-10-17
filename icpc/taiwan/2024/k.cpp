
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
	int n, m;
	cin >> n >> m;

	vector <int> g[n + 1];
	vector <int> in(n + 1, 0);

	for(int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].pb(b);
		in[b]++;
	}

	vector <bool> vis(n + 1, 0);
	priority_queue<int, vector<int>, greater<int>> pq;
	vector <int> order;

	function<void(int)> dfs = [&](int u) {
		vis[u] = true;
		order.pb(u);

		for(auto nb : g[u]) if(!vis[nb]) {
			in[nb]--;
			if(in[nb] == 0) {
				dfs(nb);
			}
		}
	};

	for(int i = 1; i <= n; i++) {
		if(in[i] == 0 && !vis[i]) {
			pq.push(i);
		}
	}

	while(!pq.empty()){
		int index = pq.top();pq.pop();
		vis[index] = true;
		order.pb(index);

		for(auto nb : g[index]) if(!vis[nb]) {
			in[nb]--;
			if(in[nb] == 0) {
				pq.push(nb);
			}
		}
	}


	if(order.size() == n) {
		for(auto i : order)
			cout << i << " ";
		cout << "\n";
		return;
	}

	cout << "IMPOSSIBLE\n";
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
