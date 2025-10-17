
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
	int n, m;
	cin >> n >> m;
	int a[n + 1][m + 1];

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int p[n + 5][m + 5][2];
	memset(p, 0, sizeof(p));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			p[i][j][0] = max(p[i][j - 1][0], a[i][j]);
		}

		for(int j = m; j >= 1; j--) {
			p[i][j][1] = max(p[i][j + 1][1], a[i][j]);
		}
	}

	int q[m + 5][n + 5][2];
	memset(q, 0, sizeof(q));

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			q[i][j][0] = max(q[i][j - 1][0], a[j][i]);
		}

		for(int j = n; j >= 1; j--) {
			q[i][j][1] = max(q[i][j + 1][1], a[j][i]);
		}
	}
	
	// for(int i = 1; i <= m; i++) {
	// 	for(int j = 1; j <= n; j++) {
	// 		cout << q[i][j][1] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";
	
	int ans = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int sum = 0;

			if(p[i][j - 1][0] < a[i][j]) sum++;
			if(p[i][j + 1][1] < a[i][j]) sum++;

			if(q[j][i - 1][0] < a[i][j]) sum++;
			if(q[j][i + 1][1] < a[i][j]) sum++;

			// debug(sum);

			ans += sum;
		}
	}
	
	cout << ans << "\n";
}

int32_t main() {
	freopen("lucky.in", "r", stdin);
	freopen("lucky.out", "w", stdout);

	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
