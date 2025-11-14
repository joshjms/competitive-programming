
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
	
	int a[n + 5][m + 5];
	memset(a, 0, sizeof(a));

	int l1 = (n + 1) / 2, r1 = (n + 1) / 2;
	int l2 = (m + 1) / 2, r2 = (n + 1) / 2;

	vector <pair<pair<int,int>, pair<int,int>>> v;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			v.pb({{max(abs(i - (n + 1) / 2), abs(j - (m + 1) / 2)), abs(i - (n + 1) / 2) + abs(j - (m + 1) / 2)}, {i, j}});
		}
	}
	sort(v.begin(), v.end());

	for(auto i : v)
		cout << i.se.fi << " " << i.se.se << "\n";
	cout << "\n";
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
