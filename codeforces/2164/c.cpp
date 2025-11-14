
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
	int n, m; cin >> n >> m;

	vector <int> a(n + 5, 0), b(m + 5, 0), c(m + 5, 0);
	vector <pair<int,int>> x, y;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	for(int i = 1; i <= m; i++)
		cin >> c[i];
	for(int i = 1; i <= m; i++) {
		if(c[i]) {
			x.pb({b[i], c[i]});
		} else {
			y.pb({b[i], c[i]});
		}
	}
	sort(x.begin(), x.end());

	multiset <int> ms;
	for(int i = 1; i <= n; i++)
		ms.insert(a[i]);

	int ans = 0;

	for(int i = 0; i < x.size(); i++) {
		int health = x[i].fi;
		int refund = x[i].se;

		// debug(refund);
		// debug(health);

		auto it = ms.lower_bound(health);
		if(it == ms.end()) continue;

		ans++;
		int val = *it;
		ms.erase(it);
		ms.insert(max(val, refund));

		// for(auto j : ms)
		// 	cout << j << " ";
		// cout << "\n";
	}

	sort(y.begin(), y.end());
	for(int i = 0; i < y.size(); i++) {
		int health = y[i].fi;
		
		auto it = ms.lower_bound(health);
		if(it == ms.end()) continue;

		ans++;
		ms.erase(it);
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
