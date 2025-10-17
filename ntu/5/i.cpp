
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
	int n, m, k;
	cin >> n >> m >> k;

	int X = 0, Y = 0;

	int a[n + 1];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 0) X++;
	}

	int b[m + 1];
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		if(b[i] == 1) Y++;
	}

	for(int i = 1, xk; i <= k; i++) {
		cin >> xk;
	}

	cout << abs(X - Y) << "\n";
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
