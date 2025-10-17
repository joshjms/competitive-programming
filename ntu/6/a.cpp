
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

double w, h;

void solve() {
	cin >> w >> h;

	double ans = 0;

	if(w / 3 <= h) {
		ans = max(ans, w / 3);
	}

	if(h * 3 <= w) {
		ans = max(ans, h);
	}

	if(h / 3 <= w) {
		ans = max(ans, h / 3);
	}

	if(w * 3 <= h)  {
		ans = max(ans, w);
	}

	if(w <= h) {
		ans = max(ans, w / 2);
	}

	if(h <= w) {
		ans = max(ans, h / 2);
	}

	cout << fixed << setprecision(6) << ans << "\n";
}

int32_t main() {
	freopen("alex.in", "r", stdin);
	freopen("alex.out", "w", stdout);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
