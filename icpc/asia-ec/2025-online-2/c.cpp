
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
	int s;
	cin >> s;

	int a[8];
	for(int i = 1; i < 8; i++)
		cin >> a[i];

	auto poss = [&](int minVal) {
		int _1 = a[1], _2 = a[2], _3 = a[4];

		// give all to _3
		_3 += a[5] + a[6];
		_2 += a[3];

		int diff = max(0ll, min(_3 - minVal, minVal - _1));
		int take = min(a[5], diff);
		_1 += take;
		_3 -= take;

		diff = max(0ll, _3 - minVal);
		take = min(a[6], diff);
		_2 += take;
		_3 -= take;

		diff = max(0ll, min(_2 - minVal, minVal - _1));
		take = min(a[3], diff);
		_1 += take;
		_2 -= take;

		// if(minVal == 13) {
		// 	debug(_1);
		// 	debug(_2);
		// 	debug(_3);
		// }

		int tmp = a[7];
		if(_1 + tmp < minVal) {
			return false;
		}
		tmp -= max(0ll, minVal - _1);
		if(_2 + tmp < minVal) {
			return false;
		}
		tmp -= max(0ll, minVal - _2);
		if(_3 + tmp < minVal) {
			return false;
		}
		tmp -= max(0ll, minVal - _3);

		return true;
	};

	int l = 0, r = 1e9, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(poss(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout << ans << "\n";
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
