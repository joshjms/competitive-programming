
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
	int n, k; cin >> n >> k;

	ld pi = acos(-1.0);

	vector <int> x(n + 5), y(n + 5);
	vector <ld> theta;
	
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		theta.pb(atan2(y[i], x[i]) + pi);
	}

	sort(theta.begin(), theta.end());

	if(n == k) {
		cout << fixed << setprecision(10) << 2 * pi << "\n";
		return;
	}
	
	for(int i = 0; i < n; i++)
		theta.pb(theta[i] + 2* pi);

	ld ans = 0;
	for(int i = 0; i < n; i++) {
		ld diff = theta[i + k] - theta[i];
		ans = max(ans, diff);
	}

	cout << fixed << setprecision(10) << ans << "\n";
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
