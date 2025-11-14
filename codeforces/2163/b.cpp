
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
	vector <int> p(n + 5);
	vector <int> pos(n + 5, -1);
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	vector <int> x(n + 5);
	for(int i = 1; i <= n; i++) {
		char c; cin >> c;
		x[i] = c - '0';
	}
	vector <int> s(n + 5, 0);

	if(x[pos[1]] || x[pos[n]]) {
		cout << -1 << "\n";
		return;
	}

	int _1 = pos[1];
	int _n = pos[n];

	vector <pair<int,int>> ans;
	ans.pb({_1, _n});
	
	for(int i = min(_1, _n) + 1; i < max(_1, _n); i++)
		s[i] = 1;

	bool ok = true;
	for(int i = 1; i <= n; i++)
		if(x[i] == 1 && s[i] == 0) {
			ok = false;
			break;
		}

	if(ok) {
		cout << ans.size() << "\n";
		for(auto i : ans) {
			cout << min(i.fi, i.se) << " " << max(i.fi, i.se) << "\n";
		}
		return;
	}
	
	if(x[1] || x[n]) {
		cout << -1 << "\n";
		return;
	}

	ans.pb({1, _1});
	ans.pb({1, _n});
	ans.pb({_1, n});
	ans.pb({_n, n});

	for(int i = 2; i < _1; i++)
		s[i] = 1;
	for(int i = 2; i < _n; i++)
		s[i] = 1;
	
	for(int i = _1 + 1; i < n; i++)
		s[i] = 1;
	for(int i = _n + 1; i < n; i++)
		s[i] = 1;

	
	ok = true;
	for(int i = 1; i <= n; i++)
		if(x[i] == 1 && s[i] == 0) {
			ok = false;
			break;
		}

	if(ok) {
		cout << ans.size() << "\n";
		for(auto i : ans) {
			cout << min(i.fi, i.se) << " " << max(i.fi, i.se) << "\n";
		}
		return;
	}

	cout << -1 << "\n";
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
