
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
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	auto fpow = [&](int x, int k) {
		int ret = 1;
		while (k) {
			if (k & 1) ret = ret * x % mod;
			x = x * x % mod;
			k >>= 1;
		}
		return ret;
	};
	// vector<int> dp(n);
	// dp[0] = a[0];
	// int ans = a[0] * fpow(2, n - 1);
	int ans = (a[1] + a[2]) * fpow(2, n - 1) % mod;
	for (int i = 3; i <= n; i++) {
		// int p = ((i * (i - 1)) % mod) * fpow(2, n - 3) % mod;
		// int p = ((i - 1) * fpow(2, i - 2) + 1) % mod;
		int p = (((fpow(3, i - 1) - 1 + mod) % mod) * fpow(2, mod - 2)) % mod + 1;
		p %= mod;
		p = p * fpow(2, n - i) % mod;
		ans += p * a[i] % mod;
		ans %= mod;
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
