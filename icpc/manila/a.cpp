
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
	int x; cin >> x;
	if(x <= -3) {
		cout << - ((x + 4) * (x + 4)) + 8 << "\n";
		return;
	}
	if(x <= 2) {
		cout << -2 * x + 1 << "\n";
		return;
	}
	cout << x * x * x + (-14) * x + 17 << "\n";
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
