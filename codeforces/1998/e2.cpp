
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
	int n, x; cin >> n >> x;
	vector <int> a(n + 5);

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector <int> ps(n + 5, 0);
	for(int i = 1; i <= n; i++)
		ps[i] = ps[i - 1] + a[i];

	auto sum = [&](int l, int r) {
		return ps[r] - ps[l - 1];
	};

	vector <pair<int,int>> tree(4 * n + 5, {0, 0});

	function <void(int, int, int)> build = [&](int idx, int l, int r) {
		if(l == r) {
			tree[idx] = {a[l], l};
			return;
		}
		int mid = (l + r) / 2;
		build(idx * 2, l, mid);
		build(idx * 2 + 1, mid + 1, r);
		tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
	};

	build(1, 1, n);

	function <pair<int,int>(int, int, int, int, int)> query = [&](int idx, int l, int r, int x, int y) {
		if(l > r || l > y || r < x) return make_pair(0ll, 0ll);
		if(l >= x && r <= y) return tree[idx];
		int mid = (l + r) / 2;
		return max(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
	};

	vector <int> ans(n + 5, 0);
	function <void(int, int, int)> get = [&](int l, int r, int posMaxi) {
		if(l > r) return;

		pair <int,int> q = query(1, 1, n, l, r);
		if(q.se < 1 || q.se > n) return;
		
		if(sum(l, r) >= a[posMaxi]) {
			ans[n]++;
			get(l, q.se - 1, q.fi);
			get(q.se + 1, r, q.fi);
		}
	};

	get(1, n, 0);
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
