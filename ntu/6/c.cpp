
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
	string s, t;
	cin >> s >> t;

	int n = s.size();
	int m = t.size();

	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < m - 1; i++)
		cnt[t[i] - 'a']++;

	// set<string> test;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		string now = "";
	// 		now += s.substr(0, i + 1);
	// 		now += t.substr(j, (m - j));
	// 		test.insert(now);
	// 	}
	// }
	// debug(test.size());

	int ans = 0;
	for(int i = 0; i < n; i++) {
		int inc = 0;

		if(i < n - 1)
			inc = m - cnt[s[i + 1] - 'a'];
		else inc = m;
		// if (m - 1 - i >= 0) cnt[t[m - 1 - i] - 'a']--;
		ans += inc;
		// debug(inc);
	}

	cout << ans << "\n";
}

int32_t main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	freopen("concatenation.in", "r", stdin);
	freopen("concatenation.out", "w", stdout);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
