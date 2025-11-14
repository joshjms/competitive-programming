
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

	vector <vector<int>> a(n + 5, vector<int>(n + 5, 0));

	int blacks = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			char c; cin >> c;
			if(c == '#') {
				a[i][j] = 1;
				blacks++;
			}
			else a[i][j] = 0;
		}
	}

	bool valid = 1;
	for(int i = 1; i <= n; i++) {
		int cons = 0;
		for(int j = 1; j <= n; j++) {
			if(a[i][j]) cons++;
			else cons = 0;

			if(cons >= 3) valid = 0;
		}
	}

	for(int i = 1; i <= n; i++) {
		int cons = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j][i]) cons++;
			else cons = 0;

			if(cons >= 3) valid = 0;
		}
	}

	if(!valid) {
		cout << "NO\n";
		return;
	}
	
	int blackies = 0;
	vector <vector<bool>> vis(n + 5, vector<bool>(n + 5, 0));

	function <void(int, int)> dfs = [&](int x, int y) {
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};

		for(int i = 0; i < 4; i++) {
			if(x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= n && a[x + dx[i]][y + dy[i]]) {
				if(!vis[x + dx[i]][y + dy[i]]) {
					vis[x + dx[i]][y + dy[i]] = 1;
					blackies++;
					dfs(x + dx[i], y + dy[i]);
				}
			}
		}
	};

	bool conn = true;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j]) {
				dfs(i, j);
				if(blackies != blacks) conn = false;
			}
		}
	}

	if(conn) {
		cout << "YES\n";
		return;
	}

	set <int> l, r;
	int maxiL = 0, maxiR = 0, miniL = 1e18, miniR = 1e18;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j]) {
				l.insert(i + j);
				maxiL = max(maxiL, i + j);
				miniL = min(miniL, i + j);
				r.insert(n - i + 1 + j);
				maxiR = max(maxiR, n - i + 1 + j);
				miniR = min(miniR, n - i + 1 + j);
			}
		}
	}

	if((l.size() <= 2 && maxiL - miniL <= 1) || (r.size() <= 2 && maxiR - miniR <= 1)) {
		cout << "YES\n";
		return;
	}

	cout << "NO\n";
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
