
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

	int a[n + 1][m + 1][26];
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char c; cin >> c;
			a[i][j][c - 'a'] = 1;
		}
	}
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
