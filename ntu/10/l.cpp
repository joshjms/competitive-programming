
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

	vector <int> a(n + 5), b(m + 5);

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= m; i++) 
		cin >> b[i];

	int s = n + m;
	vector <int> par(s + 5);

	for(int i = 0; i <= s + 4; i++)
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

	for(int i = 1; i <= n; i++) {
		if(a[i] - 1 > s) continue;
		int u = find(a[i] - 1);
		join(u, u + 1);
	}

	sort(b.begin() + 1, b.begin() + m + 1);

	int hits = 0, hitone = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > 1) hits++;
		if(a[i] == 1 && hitone == 0) hitone = 1;
	}

	hits += hitone;

	for(int i = 1; i <= m; i++) {
		int req = find(0);
		hits -= max(0ll, b[i] - req);
		join(req, req + 1);
	}

	if(hits < 0) {
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
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
