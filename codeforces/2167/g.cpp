
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
	int n; cin >> n;
	vector <int> a(n + 5), c(n + 5);

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> c[i];

	vector <pair<pair<int,int>, int>> v(n + 5);
	for(int i = 1; i <= n; i++)
		v[i] = {{-a[i], c[i]}, i};
	sort(v.begin() + 1, v.begin() + n + 5);

	int dp[n + 5];
	for(int i = 1; i <= n; i++)
		dp[i] = 1e18;
	dp[n + 1] = 0;

	for(int i = 1; i <= n; i++) {
		int val = -v[i].fi.fi;
		int cost = v[i].fi.se;
		int pos = v[i].se;

		int tot = 0;
		for(int j = n; j >= 1; j--) {
			int dc = (a[j] == val) ? 0 : c[j];
			dp[j] = min(dp[j + 1] + dc, dp[j]);
		}
	}

	cout << dp[1] << "\n";
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
