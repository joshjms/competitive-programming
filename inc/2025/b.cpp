
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

	vector <int> a(n + 5), loc(n + 5, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		loc[a[i]] = i;
	}

	if(m < n - 1) {
		cout << -1 << " " << -1 << "\n";
		return;
	}

	vector <int> lastCh(n + 5, 0);

	queue <int> q;
	q.push(1);


	for(int i = 1; i <= n; i++) {
		while(!q.empty() && lastCh[loc[q.front()]] >= a[i]) {
			q.pop();
		}
		q.push(a[i]);
		lastCh[loc[q.front()]] = a[i];
	}

	vector <pair<int,int>> edges;
	int idx = 2;

	vector <int> stopAt(n + 5, n + 1);

	for(int i = 1; i <= n && m; i++) {
		if(loc[lastCh[i]] >= idx) stopAt[i] = idx;

		for(; idx <= loc[lastCh[i]] && m; idx++) {
			edges.pb({a[i], a[idx]});
			m--;
		}
	}

	for(int i = 1; i <= n && m; i++) {
		for(int j = i + 1; j < stopAt[i] && m; j++) {
			edges.pb({a[i], a[j]});
			m--;
		}
	}

	if(m) {
		cout << -1 << " " << -1 << "\n";
		return;
	}

	for(auto i : edges) {
		cout << i.fi << " " << i.se << "\n";
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
