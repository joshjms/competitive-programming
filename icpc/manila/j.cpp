
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
	vector <vector<char>> a(n, vector<char>(m));
	vector <pair<int,int>> v;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			if(a[i][j] == '#') {
				v.pb({i, j});
			}
		}
	}

	sort(v.begin(), v.end());

	for(int j = v[0].fi; j <= v[1].fi; j++)
		a[j][v[0].se] = '#';
	for(int j = v[2].fi; j >= v[1].fi; j--)
		a[j][v[2].se] = '#';

	int l = min(v[0].se, min(v[1].se, v[2].se));
	int r = max(v[0].se, max(v[1].se, v[2].se));

	for(int i = l; i <= r; i++)
		a[v[1].fi][i] = '#';

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << "\n";
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
