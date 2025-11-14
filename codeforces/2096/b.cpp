
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
	vector <int> l(n + 1, 0), r(n + 1, 0);
	vector <pair<int,pair<int,int>>> v(n + 1, {0, {0, 0}});

	for(int i = 1; i <= n; i++)
		cin >> l[i];
	for(int i = 1; i <= n; i++) 
		cin >> r[i];

	for(int i = 1; i <= n; i++) {
		int sum = l[i] + r[i];
		int maxi = max(l[i], r[i]);
		v[i] = {sum - maxi, {sum, maxi}};
	}

	sort(v.begin() + 1, v.begin() + n + 1, greater<pair<int,pair<int,int>>>());

	int ans = 0;
	for(int i = 1; i < k; i++) {
		ans += v[i].se.fi;
	}
	for(int i = k; i <= n; i++) {
		ans += v[i].se.se;
	}
	ans += 1;
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
