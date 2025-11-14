
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
	vector <vector<char>> a(n + 5, vector<char>(m + 5, '.'));
	vector <vector<int>> t(n + 5, vector<int>(m + 5, 1e9));

	pair <int,int> S, E;

	bool vis[n + 5][m + 5];
	memset(vis, 0, sizeof(vis));
	queue <pair<int,int>> q;

	int numVir = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];

			if(a[i][j] == '*') {
				t[i][j] = 0;
				q.push({i, j});
				vis[i][j] = 1;
				numVir++;
			}
			
			if(a[i][j] == 'S') {
				S = {i, j};
			}
			if(a[i][j] == 'E') {
				E = {i, j};
			}
		}
	}

	while(!q.empty()) {
		pair <int,int> p = q.front();
		q.pop();

		int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
		int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

		for(int i = 0; i < 8; i++) {
			if(p.fi + dx[i] >= 1 && p.fi + dx[i] <= n && p.se + dy[i] >= 1 && p.se + dy[i] <= m) {
				if(!vis[p.fi + dx[i]][p.se + dy[i]]) {
					t[p.fi + dx[i]][p.se + dy[i]] = t[p.fi][p.se] + 1;
					vis[p.fi + dx[i]][p.se + dy[i]] = 1;
					q.push({p.fi + dx[i], p.se + dy[i]});
				}
			}
		}
	}

	vector <pair<int,pair<int,int>>> v;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			v.pb({t[i][j], {i, j}});
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int vSize = v.size();
	memset(vis, 0, sizeof(vis));

	vector <vector<pair<int,int>>> par(n + 5, vector<pair<int,int>>(m + 5, {-1, -1}));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			par[i][j] = {i, j};

	function<pair<int,int>(pair<int,int>)> find = [&](pair<int,int> p) {
		if(par[p.fi][p.se] == p) {
			return p;
		}
		return par[p.fi][p.se] = find(par[p.fi][p.se]);
	};

	auto join = [&](pair<int,int> u, pair<int,int> v) {
		u = find(u);
		v = find(v);

		if(u == v) return 0;

		par[u.fi][u.se] = v;
		return 1;
	};

	int idx = 0;
	for(int T = 1000000; T > 0; T--) {
		while(idx < vSize && v[idx].fi >= T) {
			int x = v[idx].se.fi;
			int y = v[idx].se.se;
			
			if(a[x][y] == '.' || a[x][y] == 'S' || a[x][y] == 'E') {
				vis[x][y] = 1;
				int dx[4] = {0, 1, 0, -1};
				int dy[4] = {1, 0, -1, 0};

				for(int i = 0; i < 4; i++) {
					if(x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m) {
						if(vis[x + dx[i]][y + dy[i]]) {
							join({x, y}, {x + dx[i], y + dy[i]});
						}
					}
				}
			}

			idx++;
		}

		if(find(S) == find(E)) {
			if(numVir == 0) {
				cout << "safe\n";
				return;
			}

			cout << T << "\n";
			return;
		}
	}

	cout << -1 << "\n";
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
