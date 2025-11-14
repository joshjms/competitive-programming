
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

	vector <int> a(n + 5);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector <int> ps(n + 5, 0), pps(n + 5, 0);
	for(int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + a[i];
		pps[i] = pps[i - 1] + ps[i];
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += ps[i] * i - pps[i - 1];
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
