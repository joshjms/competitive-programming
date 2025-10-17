
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, a[1005], b[1005];
int dp[105][2];

void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];

	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 2; j++) {
			dp[i][j] = 0;
		}
	
	dp[0][0] = 1;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			if(j == 0) {
				// no swap
				if(a[i + 1] >= a[i] && b[i + 1] >= b[i]) {
					(dp[i + 1][0] += dp[i][j]) %= mod;
				}
				if(b[i + 1] >= a[i] && a[i + 1] >= b[i]) {
					(dp[i + 1][1] += dp[i][j]) %= mod;
				}
			} else {
				// swap
				if(a[i + 1] >= b[i] && b[i + 1] >= a[i]) {
					(dp[i + 1][0] += dp[i][j]) %= mod;
				}
				if(b[i + 1] >= b[i] && a[i + 1] >= a[i]) {
					(dp[i + 1][1] += dp[i][j]) %= mod;
				}
			}
		}
	}

	cout << (dp[n][0] + dp[n][1]) % mod << "\n";
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
