
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
	int n, t;
	cin >> n >> t;
	t -= n - 1;
	vector<pair<int, int>> v;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		while (!v.empty() && x <= v.back().first) {
			v.pop_back();
		}
		v.pb({x, i + 1});
	}
	vector<int> d(n + 1);
	for (int i = 2; i < n; i++) cin >> d[i];
	int l = 0, r = v.size() - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		int ran = v[mid].second;
		deque<pair<int, int>> dq;
		dq.push_back({0, 1});
		for (int i = 2; i <= n; i++) {
			while (!dq.empty() && dq.front().second < i - ran) dq.pop_front();
			int x = dq.front().first + d[i];
			while (!dq.empty() && dq.back().first >= x) dq.pop_back();
			dq.push_back({x, i});
		}
		// cout << mid << "\n";
		// if (!dq.empty()) cout << (dq.back().first) << " " << dq.back().second << " " << t << "\n";
		if (!dq.empty() && dq.back().second == n && dq.back().first <= t) r = mid;
		else l = mid + 1;
	}
	// cout << r << "\n";
	cout << v[r].first;
}

int32_t main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
