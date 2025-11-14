
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
	int n, m, X; cin >> n >> m >> X;
	
	vector <vector<int>> h(n + 5, vector<int>(m + 5, 0));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char c; cin >> c;
			h[i][j] = c - '0';
		}
	}

	bool invalid = false;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			int sum = pow(h[i][j] - h[i + 1][j], X) + pow(h[i + 1][j] - h[i + 1][j + 1], X) + pow(h[i + 1][j + 1] - h[i][j + 1], X) + pow(h[i][j + 1] - h[i][j], X);
			if(sum != 0) {
				invalid = true;
			}
		}
	}

	if(invalid) {
		int q; cin >> q;
		for(int qq = 1; qq <= q; qq++) {
			int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
			cout << "INVALID\n";
		}

		return;
	}

	vector<vector<int>> dist(n + 5, vector<int>(m + 5, 1e18));
	priority_queue <pair<int,pair<int,int>>> pq;
	pq.push({0, {1, 1}});
	dist[1][1] = 0;

	while(!pq.empty()) {
		pair <int,pair<int,int>> p = pq.top();
		pq.pop();

		int cost = -p.fi;
		int x = p.se.fi;
		int y = p.se.se;

		if(cost > dist[x][y]) continue;

		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};
		
		for(int i = 0; i < 4; i++) {
			if(x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m) {
				int newCost = cost + pow(h[x][y] - h[x + dx[i]][y + dy[i]], X);
				if(dist[x + dx[i]][y + dy[i]] > newCost) {
					dist[x + dx[i]][y + dy[i]] = newCost;
					pq.push({-newCost, {x + dx[i], y + dy[i]}});
				}
			}
		}
	}

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= m; j++) {
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	int q; cin >> q;

	for(int qq = 1; qq <= q; qq++) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
		cout << dist[r2][c2] - dist[r1][c1]  << "\n";
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
