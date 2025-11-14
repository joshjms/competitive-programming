
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
	int n, k; cin >> n >> k;

	auto kxor = [&](int a, int b) {
		vector <int> _a, _b, _c;
		while(a) { _a.pb(a % k); a /= k; }
		while(b) { _b.pb(b % k); b /= k; }

		int sz = max(_a.size(), _b.size());
		_c.assign(sz, 0);
		for(int i = 0; i < sz; i++) {
			if(i < _a.size()) (_c[i] += _a[i]) %= k;
			if(i < _b.size()) (_c[i] += _b[i]) %= k;
		}

		int c = 0, x = 1;
		for(int i = 0; i < _c.size(); i++) { 
			c += _c[i] * x;
			x *= k;
		}

		return c;
	};

	auto rkxor = [&](int a, int b) {
		vector <int> _a, _b, _c;
		while(a) { _a.pb(a % k); a /= k; }
		while(b) { _b.pb(b % k); b /= k; }

		int sz = max(_a.size(), _b.size());
		_c.assign(sz, 0);
		for(int i = 0; i < sz; i++) {
			if(i < _a.size()) (_c[i] -= _a[i]) %= k;
			if(i < _b.size()) (_c[i] += _b[i]) %= k;

			(_c[i] += (3 * k)) %= k;
		}

		int c = 0, x = 1;
		for(int i = 0; i < _c.size(); i++) { 
			c += _c[i] * x;
			x *= k;
		}

		return c;
	};

	// int _ans = 2;

	int x = 0;
	for(int i = 0; i < n; i++) {
		// is the original password i?
		int q = (i % 2 == 0) ? kxor(i, x) : rkxor(i, x);
		cout << q << "\n";
		cout.flush();

		int resp; cin >> resp;
		if(resp == 1) {
			return;
		}

		// if(q == _ans) {
		// 	return;
		// }

		// _ans = rkxor(_ans, q);
		// debug(_ans);

		x = rkxor(x, q);
		// debug(x);
	}

	assert(false);
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
