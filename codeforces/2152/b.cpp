
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
	int n, Rk, Ck, Rd, Cd;
	cin >> n >> Rk >> Ck >> Rd >> Cd;

	pair <int,int> corners[4] = {{Rk, 0}, {Rk, n}, {0, Ck}, {n, Ck}};
	int ans = 1;

	for(int i = 0; i < 4; i++) {
		int X = corners[i].fi;
		int Y = corners[i].se;

		int kDist = abs(X - Rk) + abs(Y - Ck);
		int dDist = max(abs(X - Rd), abs(Y - Cd));

		if(kDist >= dDist) continue;

		ans = max(ans, max(abs(X - Rd), abs(Y - Cd)));
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
