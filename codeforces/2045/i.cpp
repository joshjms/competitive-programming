
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

	vector <int> a(n + 5);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector <int> lastOcc(m + 5, 0);
	
	int ans = 0;

	vector <int> tree(4 * n + 5, 0);

	function <void(int, int, int, int, int)> upd = [&](int idx, int l, int r, int x, int v) {
		if(l == r) {
			tree[idx] = v;
			return;
		}
		int mid = (l + r) /  2;
		if(x <= mid) upd(idx * 2, l, mid, x, v);
		else upd(idx * 2 + 1, mid + 1, r, x, v);
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	};

	function <int(int, int, int, int, int)> query = [&](int idx, int l, int r, int x, int y) {
		if(l > r || l > y || r < x) return 0ll;
		if(l >= x && r <= y) return tree[idx];
		int mid = (l + r) / 2;
		return query(idx * 2, l, mid, x, y) + query(idx * 2 + 1, mid + 1, r, x, y);
	};

	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(lastOcc[a[i]] == 0) {
			ans += (m - (++cnt));
			int q = query(1, 1, n, lastOcc[a[i]] + 1, i - 1);
			ans += q;
			upd(1, 1, n, i, 1);
			lastOcc[a[i]] = i;
			continue; 
		}
		int q = query(1, 1, n, lastOcc[a[i]] + 1, i - 1);
		ans += q;
		upd(1, 1, n, lastOcc[a[i]], 0);
		upd(1, 1, n, i, 1);
		lastOcc[a[i]] = i;
	}

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
