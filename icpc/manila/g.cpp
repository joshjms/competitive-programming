
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
	vector <int> l(n + 5), r(n + 5);

	int base = 0;
	vector <pair<int,int>> v;

	for(int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		if(r[i] - l[i] + 1 >= k) {
			base++;
		} else {
			int _l = l[i] % k;
			int _r = r[i] % k;

			if(_l <= _r) {
				v.pb({_l, _r});
			} else {
				v.pb({_l, k - 1});
				v.pb({0, _r});
			}
		}
	}

	sort(v.begin(), v.end());

	priority_queue <int> pq;
	int cur = 0, ans = 0;
	for(auto i : v) {
		int in = i.fi;
		int out = i.se;
		while(!pq.empty() && -pq.top() < in) {
			cur--;
			pq.pop();
		}
		cur++;
		ans = max(ans, cur);
		pq.push(-out);
	}

	cout << ans + base << "\n";
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
