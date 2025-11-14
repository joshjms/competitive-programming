
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
	vector<int> w(n);
	set<pair<int, int>> cur;
	set<int> left;
	int mx = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		sum += w[i];
		cur.insert({w[i], i});
		left.insert(i);
	}
	bool h = mx > sum - mx;
	for (int i = 1; i < n; i++) {
		mx = cur.rbegin()->first;
		h = mx > sum - mx;
		int val, idx;
		if (h) val = cur.begin()->first, idx = cur.begin()->second;
		else {
			int want = cur.rbegin()->first;
			auto f = cur.lower_bound({want, -1});
			val = f->first, idx = f->second;
		}
		cout << idx + 1 << " " << val << "\n";
		cur.erase({val, idx});
		left.erase(idx);
		sum -= val;
		auto r = left.upper_bound(idx);
		auto l = prev(r);
		if (r != left.end()) {
			cur.erase({w[*r], *r});
			w[*r] += val / 2;
			sum += val / 2;
			cur.insert({w[*r], *r});
		}
		if (r != left.begin()) {
			cur.erase({w[*l], *l});
			w[*l] += val / 2;
			sum += val / 2;
			cur.insert({w[*l], *l});
		}
	}
	cout << cur.begin()->second + 1 << " " << cur.begin()->first << "\n";
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
