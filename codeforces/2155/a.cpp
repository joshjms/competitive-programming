
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

	int w = n, l = 0;

	int ans = 0;

	while(w > 1) {
		ans += w / 2;
		l += w / 2;
		w -= w / 2;
	}

	while(l > 1) {
		ans += l / 2;
		l -= l / 2;
	}

	cout << ans + 1 << "\n";
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
