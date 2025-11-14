
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

	vector <int> a(n + 5, 0);
	vector <vector<int>> pos(n + 5, vector<int>());
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}

	vector <bool> vis(n + 5, 0);
	int ans = 0;
	
	for(int i = n - 1; i >= 1; i--) {
		int i1 = 0, i2 = 0;
		while(i1 < pos[i].size() && i2 < pos[i + 1].size()) {
			while(i1 < pos[i].size() && vis[pos[i][i1]]) i1++;
			while(i2 < pos[i + 1].size() && vis[pos[i + 1][i2]]) i2++;

			if(i1 >= pos[i].size() || i2 >= pos[i + 1].size()) break;

			if(pos[i][i1] < pos[i + 1][i2]) {
				vis[pos[i][i1]] = 1;
				vis[pos[i + 1][i2]] = 1;
				ans++;
				i1++; i2++;
			} else {
				i2++;
			}
		}
	}

	cout << ans << "\n";
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
