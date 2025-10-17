
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
	int n, m, d, x;
	cin >> n >> m >> d >> x;
	vector<pair<int, int>> slab(n);
	for (int i = 0; i < n; i++) cin >> slab[i].first >> slab[i].second;
	sort(slab.begin(), slab.end());
	vector<int> pre(n + 1), suf(n + 1);
	int cur = m;
	for (int i = n - 1; i >= 0; i--) {
		suf[i] = cur - slab[i].second;
		cur = slab[i].first - d - 1;
		// cout << i << " " << suf[i] << "\n";
	}
	int ans = 1e18;
	int need = x + d - (slab[0].first) + 1, r = 0, cost = 0;
	while (need > 0 && r < n) {
		int rr = (r + 1) * min(need, suf[r]);
		// cout << need << " " << rr << "\n";
		cost += rr;
		need -= suf[r];
		r++;
	}
	if (need <= 0) ans = cost;
	cur = 1;
	for (int i = 0; i < n; i++) {
		pre[i] = slab[i].first - cur;
		cur = slab[i].second + d + 1;
		// cout << "pre " << i << " " << pre[i] << "\n";
		int l = i, r = i + 1;
		if (i < n) need = x + 2 * d - (slab[i + 1].first - slab[i].second) + 1;
		if (i == n - 1) need = x + d - (m - slab[i].second);
		int cost = 0;
		while (need > 0) {
			int ll = 1e18, rr = 1e18;
			if (l >= 0) {
				ll = min(need, pre[l]) * (i - l + 1);
			}
			if (r < n) {
				rr = (r - i) * min(need, suf[r]);
			}
			if (ll == 1e18 && rr == 1e18) {
				cost = 1e18;
				break;
			}
			// cout << "n " << need << " " << ll << " " << rr << "\n";
			if (ll < rr) {
				cost += ll;
				need -= pre[l];
				l--;
			}
			else {
				cost += rr;
				need -= suf[r];
				r++;
			}
		}
		// cout << i << " " << i+1 << " " << cost << "\n";
		ans = min(ans, cost);
	}
	// for (int i = 0; i < n; i++) cout << pre[i] << " ";
	// cout << "\n";
	if (ans == 1e18) cout << -1;
	else cout << ans;
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
