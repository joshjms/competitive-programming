
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector <int> a(n + 5);

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector <int> pfct(1000005, 0);
	
	for(int i = 2; i <= 1000000; i++) {
		if(pfct[i] == 0) {
			pfct[i] = i;
			for(int j = i * i; j <= 1000000; j += i)
				pfct[j] = i;
		}
	}

	vector <pair<int,int>> v[1000005];

	for(int i = 1; i <= n; i++) {
		int tmp = a[i];
		while(tmp > 1) {
			int f = pfct[tmp];
			int c = 0;

			while(tmp % f == 0) {
				c++;
				tmp /= f;
			}

			v[f].pb({i, c});
		}
	}

	int ans = 1;

	for(int i = 2; i <= 1000000; i++) {
		if(pfct[i] != i) continue;

		vector <vector<pair<int,int>>> pika;
		vector <pair<int,int>> tmp;
		for(auto j : v[i]) {
			if(!tmp.empty() && tmp.back().fi + 1 != j.fi) {
				pika.pb(tmp);
				tmp.clear();
			}
			tmp.pb(j);
		}
		if(!tmp.empty()) { pika.pb(tmp); tmp.clear(); }
		
		if(pika.empty()) continue;

		// debug(i);

		for(auto j : pika) {
			// for(auto ii : j)
			// 	cout << ii.se << " ";
			// cout << "\n";

			int ts = j.size();
			int dp[ts + 1][21];
			memset(dp, 0, sizeof(dp));

			dp[0][0] = 1;
			if(j[0].fi == 1) {
				for(int ii = 1; ii <= 20; ii++)
					dp[0][ii] = 1;
			}

			for(int ii = 1; ii <= ts; ii++) {
				int sum = 0;
				int need = j[ii - 1].se;
				for(int jj = 0; jj < need; jj++) {
					(sum += dp[ii - 1][jj]) %= mod;
					(dp[ii][jj] += dp[ii - 1][need]) %= mod;
				}
				(dp[ii][need] += dp[ii - 1][need]) %= mod;
				(dp[ii][need] += sum) %= mod;
			}

			// for(int ii = 0; ii <= ts; ii++) {
			// 	for(int jj = 0; jj <= 20; jj++) {
			// 		cout << dp[ii][jj] << " ";
			// 	}
			// 	cout << "\n";
			// }

			int res = dp[ts][0];

			if(j.back().fi == n) {
				for(int ii = 1; ii <= 20; ii++)
					(res += dp[ts][ii]) %= mod;
			}

			(ans *= res) %= mod;
		}
	}

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
