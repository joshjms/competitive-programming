
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

	for(int i = 1; i <= n; i++) {
		char c; cin >> c;
		if(c == 'B') a[i] = 1;
		else a[i] = 0;
	}

	vector <pair<int,int>> v;

	for(int i = 1; i <= n; i++) {
		if(i == 1 || a[i] != a[i - 1]) {
			v.pb({a[i], 0});
		}
		v.back().se++;
	}

	if(v.size() == 1) {
		cout << 0 << "\n";
		return;
	}

	int N = v.size(), ans = 0, ctr = 0;

	while(v.size() > 1) {
		if(v.back().fi == 0) {
			v.pop_back();
			continue;
		}
		
		int cnt = v.back().se;
		v.pop_back();

		int steps = v.back().se;
		v.pop_back();

		int ops = (cnt % 2 ? (steps + 1) / 2 : 0) + (cnt / 2) * steps;
		ans += ops;

		if(!v.empty())
			v.back().se += cnt;
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
