
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
	vector <int> a(n + 1, 0);

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	pair <int,pair<int,int>> res = {0, {0, 0}};
	int sum = 0, l = 1, r = 1;
	for(int i = 1; i <= n; i++, r++) {
		if(a[i] < 0) 
			sum += 3 * a[i];
		else
			sum += a[i];

		res = max(res, {sum, {l, r}});

		if(sum < 0) {
			sum = 0;
			l = i + 1;
			r = i;
		}
	}

	// debug(res.se.fi);
	// debug(res.se.se);

	for(int i = res.se.fi; i <= res.se.se; i++) {
		
		a[i] *= 2;
	}

	for(int i = 1; i < res.se.fi; i++)
		a[i] = abs(a[i]);

	for(int i = res.se.se + 1; i <= n; i++)
		a[i] = abs(a[i]);

	// debug(res.fi);
	// debug(res.se.fi);
	// debug(res.se.se);

	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += a[i];

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
