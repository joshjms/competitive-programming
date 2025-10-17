
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
	int n, m; cin >> n >> m;

	if(n * n - m == 1) {
		cout << "NO\n";
		return;
	}

	m = n * n - m;

	int a[n + 1][n + 1];
	memset(a, 0, sizeof(a));

	for(int i = 1; i <= n; i++) {
		if(m == 0) continue;

		int x = min(n, m);
		int I = n - x + 1;
		m -= x;

		a[I][i] = 1;
		if(I == n) a[I][i] = 2;
	}

	cout << "YES\n";

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << (a[i][j] == 0 ? "U" : a[i][j] == 1 ? "D" : "L");
		}
		cout << "\n";
	}
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
