
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
	int n, k;
	cin >> n >> k;

	vector <int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector<vector<pair<int,int>>> v(200005);

	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i - 1]) {
			if(i > 1 && cnt > 0) v[1].pb({a[i - 1], cnt});
			cnt = 0; 
		}
		cnt++;
	}
	if(cnt > 0) v[1].pb({a[n], cnt});

	int sz = 1;
	for(int op = 1; op <= min(k, 50ll); op++) {
		for(int i = 1; i <= min(sz, 200000ll); i++) {
			vector <pair<int,int>> l, r;
			int cur = 0;

			for(auto j : v[i]) {
				int num = j.fi;
				int cnt = j.se;

				if(cur < n) {
					if(cur + cnt * 2 > n) {
						l.pb({num, n - cur});
						r.pb({num, cnt * 2 - (n - cur)});
						cur += cnt * 2;
					} else {
						l.pb({num, cnt * 2});
						cur += cnt * 2;
					}
				} else {
					r.pb({num, cnt * 2});
					cur += cnt * 2;
				}
			}

			assert(cur == n * 2);
			v[i] = l;
			if(i + sz <= 200000) v[i + sz] = r;
		}
		sz *= 2;
	}

	for(int i = 1; i <= min(sz, 200000ll); i++) {
		int sum = 0;
		for(auto j : v[i]) {
			sum += j.fi * j.se;
		}
		cout << sum << "\n";
	}
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
