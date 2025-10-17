
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
	vector<int> v(n), cnt(64);
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (int j = 0; j < 64; j++) {
			if ((v[i] >> j) & 1ll) {
				cnt[j]++;
			}
		}
		pq.push({v[i], i});
	}
	vector<pair<int, int>> ans;
	while (!pq.empty()) {
		auto [x, i] = pq.top();
		// debug(pq.top().fi);
		pq.pop();
		ans.pb({i, x});
		bool first = true;
		for (int j = 63; j >= 0; j--) {
			if ((x >> j) & 1ll) {
				if (first && cnt[j] > 2) return void(cout << -1 << "\n");
				first = false;
				cnt[j]--;
			}
		}
		if (pq.empty()) break;
		auto [y, ii] = pq.top();
		pq.pop();
		for (int j = 0; j < 64; j++) {
			if ((y >> j) & 1ll) {
				cnt[j]--;
			}
		}
		if ((x ^ y) == 0) continue;
		pq.push({x ^ y, ii});
		for (int j = 0; j < 64; j++) {
			if (((x ^ y) >> j) & 1ll) {
				cnt[j]++;
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto [i, x] : ans) {
		cout << i + 1 << " " << x << "\n";
	}
	// cout << "\n";
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
