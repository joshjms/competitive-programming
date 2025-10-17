
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

	int _r = r;

	int ans = 0;
	int a[r - l + 1 + 1];
	memset(a, 0, sizeof(a));

	// for(int i = 1; i <= (r - l + 1); i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << "\n";

	assert(l == 0);
	for(int i = 31; i >= 0; i--) {
		if(r >= _2[i]) {
			int X = _2[i] - 1;
			int Y = _2[i];

			while(Y <= r) {
				ans += 2 * (X | Y);
				a[X] = Y;
				a[Y] = X;
				Y++; X--;
			}

			r = X;
		}
	}

	cout << ans << "\n";
	for(int i = l; i <= _r; i++) {
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
