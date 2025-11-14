
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
	
	int idx = n * m;

	a[1][1] = idx--;

	queue <pair<int,int>> q;
	q.push({1, 1});

	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().se;

		q.pop();

		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};

		for(int i = 0; i < 4; i++) {
			if(x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m) {
				if(a[x + dx[i]][y + dy[i]] == 0) {
					a[x + dx[i]][y + dy[i]] = idx--;
					q.push({x + dx[i], y + dy[i]});
				}
			}
		}
	}

	cout << "YES\n";

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << a[i][j] << " ";  
		}
		cout << "\n";
	}
	
	// set <int> st;

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= m; j++) {
	// 		if(j < m) {
	// 			int sum = a[i][j] + a[i][j + 1];
	// 			assert(!st.count(sum));
	// 			st.insert(sum);
	// 		}
	// 		if(i < n) {
	// 			int sum = a[i][j] + a[i + 1][j];
	// 			assert(!st.count(sum));
	// 			st.insert(sum);
	// 		}
	// 	}
	// }
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
