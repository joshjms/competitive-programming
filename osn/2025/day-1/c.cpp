
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
	int n = 24;

	cout << n << "\n";
	cout.flush();

	vector <vector<pair<int,int>>> a(n + 5, vector<pair<int,int>>(n + 5, {0, 0}));

	int maxSz = 24, sum = 0;
	
	// vector <int> v(maxSz + 1, 0);
	// for(int i = 1; i <= maxSz; i++) {
	// 	if(i == 1) v[i] = 3;
	// 	else if(i == 2) v[i] = 6;
	// 	else v[i] = (maxSz / i);
	// 	sum += v[i] * i;
	// }
	// cout << sum * 3 - n * n << "\n";

	// for(int i = 1; i <= maxSz; i++) {
	// 	cout << v[i] << " ";
	// }
	// cout << "\n";
	
	int cur = 0, l = 0;
	for(int i = 1; i <= n;) {
		for(int k = 0; k < 3; k++) {
			for(int j = 1; j <= l; j++) {
				a[i][j] = {cur + 1, l};
			}
			cur = (cur + 1) % 3;
			for(int j = l + 1; j <= n; j++) {
				a[i][j] = {cur + 1, n - l};
			}
			cur = (cur + 1) % 3;
			i++;
		}
		l++;
	}

	vector <vector <int>> vis(n + 5, vector <int> (n + 5, 0));
	function <int(int, int)> dfs = [&](int x, int y) {
		vis[x][y] = 1;
		int ret = 1;

		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};

		for(int i = 0; i < 4; i++) {
			if(x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= n) {
				if(a[x + dx[i]][y + dy[i]] == a[x][y] && !vis[x + dx[i]][y + dy[i]]) {
					ret += dfs(x + dx[i], y + dy[i]);
				}
			}
		}

		return ret;
	};

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= n; j++) {
	// 		cout << a[i][j].fi << " ";
	// 	}
	// 	cout << "\n";
	// }

	int cnt[4][30];
	memset(cnt, 0, sizeof(cnt));
	int maxi = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(!vis[i][j]) {
				int ret = dfs(i, j);
				cnt[a[i][j].fi][ret]++;
				maxi = max(maxi, cnt[a[i][j].fi][ret] * ret);
			}
		}
	}

	cout << "QUERY\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j].fi << " ";
		}
		cout << "\n";
	}
	cout.flush();

	int s, m; cin >> s >> m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] != make_pair(s, m)) {
				a[i][j] = {0, 0};
			}
		}
	}

	vector <pair <int,int> > q2 = {{1, 1}, {2, 1}, {3, 1}, {1, 1}, {2, 1}, {3, 1}, {1, 1}, {2, 1}, {3, 1}, {1, 2}, {2, 2}, {3, 2}, {1, 3}, {2, 3}, {3, 3}};
	reverse(q2.begin(), q2.end());

	// for(auto i : q2) {
	// 	cout << i.fi << " " << i.se << "\n";
	// }

	set <pair<int,int>> st;

	int idx = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] == make_pair(0ll, 0ll) || st.count({i, j})) continue;

			while(j + q2[idx].se - 1 > n || a[i][j + q2[idx].se - 1] == make_pair(0ll, 0ll) || a[i][j - 1].fi == q2[idx].fi) idx++;

			pair <int,int> p = q2[idx];
			idx++;
			int e = j + p.se;
			for(int k = j; k < e; k++) {
				a[i][k] = p;
				st.insert({i, k});
			}
		}
	}

	cout << "QUERY\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j].fi << " ";
		}
		cout << "\n";
	}
	cout.flush();

	cin >> s >> m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] != make_pair(s, m)) {
				a[i][j] = {0, 0};
			}
		}
	}

	vector <pair<int,int>> q3 = {{1, 1}, {2, 1}, {3, 1}};
	idx = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] == make_pair(0ll, 0ll)) continue;

			pair <int,int> p = q3[idx++];
			a[i][j] = p;
		}
	}
	
	// cout << "ANSWER\n";
	// cout << 1 << " " << 1 << "\n";
	// cout.flush();
	
	// return;

	cout << "QUERY\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j].fi << " ";
		}
		cout << "\n";
	}
	cout.flush();

	cin >> s >> m;	
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] != make_pair(s, m)) {
				a[i][j] = {0, 0};
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] != make_pair(0ll, 0ll)) {
				cout << "ANSWER\n";
				cout << i << " " << j << "\n";
				cout.flush();
				return;
			}
		}
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
