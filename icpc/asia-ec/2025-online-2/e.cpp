
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int modex(int a, int b) {
	int res = 1; 
	while(b) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;

	int nums = (modex(2, m) - 1 + mod) % mod;
	if(n & 1) {
		cout << modex(nums, n - 1) << "\n";
		return;
	}

	if(n % 4 == 0) {
		int ans = modex(nums, n / 2);
		(ans *= (modex(nums, n / 2 - 1) + 1) % mod) %= mod;
		cout << ans << "\n";
		return;
	}

	int ans = modex(nums, n / 2);
	(ans *= (modex(nums, n / 2 - 1) - 1) % mod) %= mod;
	cout << ans << "\n";
	return;
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
