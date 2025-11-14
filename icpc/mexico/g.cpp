
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
	int h1, h2, b;
	cin >> h1 >> h2 >> b;
	cout << (int) ceil(log(1.0*h2/(1.0*h1))/log((b-1.0)/(b * 1.0))) << "\n";

	// ld _h1 = h1, _h2 = h2, _b = b;
	// int ans = 0;
	// while(_h1 > _h2) {
	// 	_h1 = _h1 * (_b - 1.0)/(_b);
	// 	ans++;
	// }

	// cout << ans << "\n";
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
