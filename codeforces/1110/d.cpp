
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve() {
	int n, m; cin >> n >> m;

	vector <int> a(n + 5), cnt(m + 5, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	int dp[m + 5][7][7];
	memset(dp, -1, sizeof(dp));
	dp[1][0][0] = 0;

	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < 7; j++) {
			for(int k = 0; k < 7; k++) {
				if(dp[i][j][k] == -1) continue;
				int c = cnt[i];

				for(int kk = 0; kk < 7; kk++) {
					if(c < kk) break;
					int _777 = (c - kk) / 3;
					int _123 = c - _777 * 3 - kk;
					if(min(j, k) < _123) continue;

					dp[i + 1][k - _123][kk] = max(dp[i + 1][k - _123][kk], dp[i][j][k] + _777 + _123);
				}
			}
		}
	}

	// for(int i = 1; i <= m + 1; i++) {
	// 	for(int j = 0; j < 3; j++) {
	// 		for(int k = 0; k < 3; k++) {
	// 			cout << dp[i][j][k] << " ";
	// 		}
	// 	}
	// 	cout << "\n";
	// }

	int ans = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			ans = max(ans, dp[m + 1][i][j]);
		}
	}

	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
