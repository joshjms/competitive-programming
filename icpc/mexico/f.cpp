
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
	// code here
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	for (int i = 0; i < n; i++) cin >> a[i];
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int k;
	cin >> k;
	set<string> st;
	for (int i = 0; i < k; i++) {
		string tmp;
		cin >> tmp;
		st.insert(tmp);
	}
	vector<string> v;
	for(auto i : st) v.pb(i);
	if (sx == tx && sy == ty) {
		cout << 0;
		return;
	}
	vector<pair<pair<int, int>, int>> adj[n][m];
	// map<pair<int, int>, int> mp[n][m];
	// int exist[n][m][n][m];
	// for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int ii = 0; ii < n; ii++) for (int jj = 0; jj < m; jj++) exist[i][j][ii][jj] = 1e9;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			for (auto s : v) {
				int nx = x, ny = y, cnt = 0;
				for (auto i : s) {
					int xx = nx, yy = ny;
					if (i == 'U') xx--;
					else if (i == 'D') xx++;
					else if (i == 'L') yy--;
					else yy++;
					if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == '0') nx = xx, ny = yy, cnt++;
				}
				// if (mp[x][y].count({nx, ny})) mp[x][y][{nx, ny}] = min(mp[x][y][{nx, ny}], cnt);
				// else mp[x][y][{nx, ny}] = cnt;
				// exist[x][y][nx][ny] = min(exist[x][y][nx][ny], cnt);
				adj[x][y].push_back({{nx, ny}, cnt});
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		for (auto [p, w] : mp[i][j]) adj[i][j].pb({p, w}); 
	// 	}
	// }
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	vector<vector<int>> vis(n, vector<int>(m, 1e9));
	q.push({0, {sx ,sy}});
	vis[sx][sy] = 0;
	while (!q.empty()) {
		auto [cnt, p] = q.top();
		auto [x, y] = p;
		q.pop();
		if (cnt != vis[x][y]) continue;
		if (x == tx && y == ty) {
			cout << cnt;
			return;
		}
		// cout << x << " " << y << "\n";
		for (auto [p, w] : adj[x][y]) {
			// cout << xx << " " << yy << "\n";
			auto [xx, yy] = p;
			if (vis[xx][yy] > vis[x][y] + w) {
				q.push({vis[xx][yy] = vis[x][y] + w, {xx, yy}});
			}
		}
		// for (auto s : v) {
		// 	int nx = x, ny = y;
		// 	for (auto i : s) {
		// 		int xx = nx, yy = ny;
		// 		if (i == 'U') xx--;
		// 		else if (i == 'D') xx++;
		// 		else if (i == 'L') yy--;
		// 		else yy++;
		// 		if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == '0') nx = xx, ny = yy;
		// 	}
		// 	// cout << s << " " << nx << " " << ny << "\n";
		// 	if (vis[nx][ny] > cnt) {
		// 		if (nx == tx && ny == ty) {
		// 			cout << cnt;
		// 			return;
		// 		}
		// 		q.push({cnt, {nx, ny}});
		// 		vis[nx][ny] = cnt;
		// 	}
		// }
	}
	cout << -1;
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
