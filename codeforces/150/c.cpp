
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
	int n, m, c; cin >> n >> m >> c;

	vector <int> x(n + 5, 0), cost(n + 5, 0);
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		if(i > 1) cost[i - 1] = x[i] - x[i - 1];
	}

	vector <int> pc(n + 5, 0);
	for(int i = 1; i < n; i++)
		pc[i] = pc[i - 1] + cost[i];

	vector <ld> p(n + 5, 0);
	for(int i = 1; i < n; i++) {
		cin >> p[i];
		p[i] /= 100.0;
	}

	vector <pair<int,int>> a(m + 5);
	vector <int> in(n + 5, 0), out(n + 5, 0);
	for(int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;
		a[i] = {l, r};
	}

	vector <ld> exp(n + 5, 0);

	int idx = 1, cur = 0;
	priority_queue <int> pq;
	for(int i = 1; i < n; i++) {
		exp[i] = (cost[i] / 2.0) * (1 - p[i]) + ((cost[i] / 2.0) - c) * (p[i]);
	}
	
	struct Node {
		ld mss = 0, ps = 0, ss = 0, s = 0;
		Node() {
			mss = 0, ps = 0, ss = 0, s = 0;
		}
		Node(ld v) {
			mss = v, ps = v, ss = v, s = v;
		}
	};

	vector <Node> tree(4 * n + 5, Node(0));

	function <void(int, int , int)> build = [&](int idx, int l, int r) {
		if(l == r) {
			tree[idx] = Node(exp[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(idx * 2, l, mid);
		build(idx * 2 + 1, mid + 1, r);
		tree[idx].s = tree[idx * 2].s + tree[idx * 2 + 1].s;
		tree[idx].ps = max(tree[idx * 2].ps, tree[idx * 2].s + tree[idx * 2 + 1].ps);
		tree[idx].ss = max(tree[idx * 2 + 1].ss, tree[idx * 2 + 1].s + tree[idx * 2].ss);
		tree[idx].mss = max(tree[idx * 2].mss, max(tree[idx * 2 + 1].mss, tree[idx * 2].ss + tree[idx * 2 + 1].ps));
	};

	build(1, 1, n - 1);

	function <Node(int, int, int, int, int)> query = [&](int idx, int l, int r, int x, int y) {
		if(l > r || l > y || r < x) return Node(0.0);
		if(l >= x && r <= y) return tree[idx];

		int mid = (l + r) / 2;
		Node ql = query(idx * 2, l, mid, x, y);
		Node qr = query(idx * 2 + 1, mid + 1, r, x, y);

		Node res;
		res.s = ql.s + qr.s;
		res.ps = max(ql.ps, ql.s + qr.ps);
		res.ss = max(qr.ss, qr.s + ql.ss);
		res.mss = max(ql.mss, max(qr.mss, ql.ss + qr.ps));

		return res;
	};

	ld ans = 0.0;
	for(int i = 1; i <= m; i++) {
		Node res = query(1, 1, n - 1, a[i].fi, a[i].se - 1);
		ans += max((ld) 0, res.mss);
	}

	cout << fixed << setprecision(6) << ans << "\n";
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
