
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int _3[65], m3;

void solve() {
	// code here
	int n;
	cin >> n;
	int m = 1;
	auto log3 = [&](int x) {
		int ret = 0;
		for(int i = 0; i <= m3; i++) {
			if(_3[i] <= x) ret = i;
			else break;
		}
		return ret;
	};
	auto log2 = [&](int x) {
		int ret = 0;
		for(int i = 0; i < 63; i++) {
			if(x % (1ll << i) == 0) ret = i;
			else break;
		}
		return ret;
	};
	vector<int> ans;
	while (n) {
		// cout << n << "\n";
		if (n & 1) {
			int k = log3(n);
			n -= _3[k];
			ans.pb(_3[k] * m);
		}
		else {
			int k = log2(n);
			int x = (1ll << k);
			// cout << k << " " << x << "\n";
			n /= x;
			if (n == 1) {
				ans.pb(x * m);
				break;
			}
			m *= x;
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans) cout << i << " ";
	cout << "\n";
}

int32_t main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	freopen("distribution.in", "r", stdin);
	freopen("distribution.out", "w", stdout);

	_3[0] = 1;
	for(int i = 1; i < 60; i++) {
		if(_3[i - 1] * 3 > 1e18) break;
		_3[i] = (_3[i - 1] * 3);
		m3 = i;
	}

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
