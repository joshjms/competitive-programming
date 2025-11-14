
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
	int n;
	cin >> n;
	vector<int> adj[n];
	vector<int> a(n), b(n), deg(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			x--;
			adj[x].pb(i);
			deg[i]++;
		}
	}
	queue<int> q;
	int mxa = 0, mxb = 0;
	for (int i = 0; i < n; i++) if (deg[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (mxb == 0 || (a[u] * mxb > mxa * b[u])) mxa = a[u], mxb = b[u];
		for (auto v : adj[u]) {
			deg[v]--;
			b[v] = max(b[v], b[u]);
			if (deg[v] == 0) q.push(v);
		}
	}
	// cout << mxa << " " << mxb << "\n";
	for (int i = 0; i < n; i++) {
		// cout << i << " " << a[i] << " " << b[i] << "\n";
		if (a[i] * mxb == b[i] * mxa) cout << i + 1 << "\n";
	}
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
