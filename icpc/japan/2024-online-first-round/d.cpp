
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

bool solve() {
	int n; cin >> n;
	if(n == 0) return 1;

	int a, b, d; cin >> a >> b >> d;
	vector <int> x(n + 5), y(n + 5);

	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];

	vector <vector<vector<int>>> dist(105, vector<vector<int>>(105, vector<int>(4, 0)));
	vector <vector<vector<bool>>> vis(105, vector<vector<bool>>(105, vector<bool>(4, 0)));

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 4; j++)
			dist[x[i]][y[i]][j] = -1;
	}

	int dir = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	auto chdir = [&]() {
		dir = (dir + 1) % 4;
	};
	
	int cx = a, cy = b, prv = -1;
	dist[cx][cy][dir] = 0;

	int _d = d;

	while(d) {
		int cd = prv + 1;

		if(cx + dx[dir] < 0 || cy + dy[dir] < 0 || cx + dx[dir] > 100 || cy + dy[dir] > 100) {
			cout << cx + dx[dir] * (d) << " " << cy + dy[dir] * (d) << "\n";
			return 0;
		}

		while(dist[cx + dx[dir]][cy + dy[dir]][dir] == -1) {
			chdir();

			if(cx + dx[dir] < 0 || cy + dy[dir] < 0 || cx + dx[dir] > 100 || cy + dy[dir] > 100) {
				cout << cx + dx[dir] * (d) << " " << cy + dy[dir] * (d) << "\n";
				return 0;
			}
		}

		if(vis[cx][cy][dir]) {
			int cycleLength = cd - dist[cx][cy][dir];
			if(cycleLength)
				d %= cycleLength;
		}

		if(d == 0) {
			cout << cx << " " << cy << "\n";
			return 0;
		}

		vis[cx][cy][dir] = 1;
		dist[cx][cy][dir] = cd;
		prv = cd;

		cx += dx[dir];
		cy += dy[dir];

		d--;
	}

	cout << cx << " " << cy << "\n";

	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (true) {
		if(solve()) break;
	}

	return 0;
}
