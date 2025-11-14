
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
	int a, b;
	cin >> a >> b;
	unordered_map<int, int> dp[a + 1];
	function<int(int, int)> dfs = [&](int x, int y) {
		if (dp[x].count(y)) return dp[x][y];
		if (x == 0) return dp[x][y] = 1;
		if (gcd(x, y) == x) return dp[x][y] = 2;
		if ((b / x) * x > y) return 1000000000000ll;
		int d = gcd(x, y);
		return dp[x][y] = min(dfs(x - d, y), dfs(x, y - d)) + 1;
	};
	cout << dfs(a, b) << "\n";
	// int ans = LLONG_MAX, cnt = 0;
	// auto cal = [&](int x, int y) {
	// 	int ret = 0;
	// 	while (gcd(x, y) != x) {
	// 		y -= gcd(x, y);
	// 		ret++;
	// 	}
	// 	return ret;
	// };
	// while (a > 0) {
	// 	int cnt2 = cal(a, b);
	// 	ans = min(ans, cnt + cnt2 + 2);
	// 	cout << a << " " << b << " " << cnt << " " << cnt2 << " " << ans << "\n";
	// 	int temp = gcd(a, b);
	// 	a -= temp; 
	// 	if(gcd(a,b - temp) == temp) {
	// 		b -= temp;
	// 		cnt++;
	// 	}
	// 	// cnt++;
	// 	cnt++;
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
