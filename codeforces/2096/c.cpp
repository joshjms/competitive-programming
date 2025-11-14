
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
	int A[n + 5][n + 5];
	memset(A, 0, sizeof(A));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}

	int a[n + 1], b[n + 1];
	for(int i = 1; i <= n; i++)	
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];

	int dp[n + 5][2], dp2[n + 5][2];
	for(int i = 1; i <= n; i++) {
		dp[i][0] = 1e18;
		dp[i][1] = 1e18;
		dp2[i][0] = 1e18;
		dp2[i][1] = 1e18;
	}

	dp[1][0] = 0;
	dp[1][1] = a[1];
	dp2[1][0] = 0;
	dp2[1][1] = b[1];

	for(int i = 1; i < n; i++) {
		for(int k = 0; k < 2; k++) {
			if(dp[i][k] >= 1e18) continue;

			for(int nk = 0; nk < 2; nk++) {
				bool valid = true;

				for(int j = 1; j <= n; j++) {
					if(A[i][j] + k == A[i + 1][j] + nk) {
						valid = false;
						break;
					}
				}

				if(!valid) continue;

				dp[i + 1][nk] = min(dp[i + 1][nk], dp[i][k] + (nk ? a[i + 1] : 0));
			}
		}
	}

	// for(int i = 1; i <= n; i++) {
	// 	for(int k = 0; k < 2; k++) {
	// 		cout << dp[i][k] << " ";
	// 	}
	// 	cout << "\n";
	// }

	for(int i = 1; i < n; i++) {
		for(int k = 0; k < 2; k++) {
			if(dp2[i][k] >= 1e18) continue;
			for(int nk = 0; nk < 2; nk++) {
				bool valid = true;
				for(int j = 1; j <= n; j++) {
					if(A[j][i] + k == A[j][i + 1] + nk) {
						valid = false;
						break;
					}
				}

				if(!valid) continue;

				dp2[i + 1][nk] = min(dp2[i + 1][nk], dp2[i][k] + (nk ? b[i + 1] : 0));
			}
		}
	}

	int ans = min(dp[n][0], dp[n][1]) + min(dp2[n][0], dp2[n][1]);

	if(ans >= 1e18) {
		cout << -1 << "\n";
		return;
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
