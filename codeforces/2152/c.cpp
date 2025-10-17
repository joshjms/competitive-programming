
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
	int n, q;
	cin >> n >> q;

	int a[n + 1], p[n + 1][2];
	memset(p, 0, sizeof(p));

	int alternateSince[n + 1];
	memset(alternateSince, 0, sizeof(alternateSince));

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i][0] += p[i - 1][0];
		p[i][1] += p[i - 1][1];
		p[i][a[i]]++;
	}

	a[0] = a[1];
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i - 1]) {
			alternateSince[i] = alternateSince[i - 1];
		} else {
			alternateSince[i] = i;
		}
	}

	for(int t = 1; t <= q; t++) {
		int l, r; cin >> l >> r;

		if((p[r][0] - p[l - 1][0]) % 3 || (p[r][1] - p[l - 1][1]) % 3) {
			cout << -1 << "\n";
			continue;
		}

		int ans = (r - l + 1) / 3;

		if(alternateSince[r] <= l) {
			ans++;
		}

		cout << ans << "\n";
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
