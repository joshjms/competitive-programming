
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int _2[35];

void solve() {
	int l, r;
	cin >> l >> r;

	int _l = l;
	int _r = r;

	int ans = 0;
	int a[r - l + 1 + 1];
	memset(a, -1, sizeof(a));

	// for(int i = 1; i <= (r - l + 1); i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << "\n";

	for(int i = 31; i >= 0; i--) {
		if(l > _r || r < _l) break;
		if(r - l + 1 <= _2[i] * 2) {
			if((_2[i] & l) == (_2[i] & r)) continue;

			// debug(l);
			// debug(r);
			// debug(_2[i]);

			if(_2[i] & l) {
				int ll = l;
				int rr = r;
				int pos = -1;

				while(ll <= rr) {
					int mid = (ll + rr) / 2;
					if(mid & _2[i]) {
						pos = mid;
						ll = mid + 1;
					} else {
						rr = mid - 1;
					}
				}

				int X = pos;
				int Y = pos + 1;

				while(Y <= r && X >= l) {
					ans += 2 * (X | Y);
					a[X - _l] = Y;
					a[Y - _l] = X;
					Y++; X--;
				}

				if(Y > r) {
					r = X;
				}
				if(X < l) {
					l = Y;
				}
			} else {
				int ll = l;
				int rr = r;
				int pos = -1;

				while(ll <= rr) {
					int mid = (ll + rr) / 2;
					if(mid & _2[i]) {
						pos = mid;
						rr = mid - 1;
					} else {
						ll = mid + 1;
					}
				}

				int Y = pos;
				int X = pos - 1;

				while(Y <= r && X >= l) {
					ans += 2 * (X | Y);
					a[X - _l] = Y;
					a[Y - _l] = X;
					Y++; X--;
				}

				if(Y > r) {
					r = X;
				}
				if(X < l) {
					l = Y;
				}
			}
		}
	}

	for(int i = 0; i <= _r - _l; i++) {
		if(a[i] == -1) {
			a[i] = i + _l;
			ans += i + _l;
		}
	}

	cout << ans << "\n";
	for(int i = 0; i <= _r - _l; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	_2[0] = 1;
	for(int i = 1; i < 32; i++) {
		_2[i] = _2[i - 1] * 2;
	}

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
