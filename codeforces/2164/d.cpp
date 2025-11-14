
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
	int n, k; cin >> n >> k;
	string s, t; cin >> s >> t;

	vector <vector<int>> lastOcc(n, vector<int>(26, -1));
	vector <int> prv(n + 5);

	for(int i = 0; i < n; i++) {
		if(i) {
			for(int j = 0; j < 26; j++) {
				lastOcc[i][j] = lastOcc[i - 1][j];
			}
		}
		lastOcc[i][s[i] - 'a'] = i;
	}

	int j = n - 1;
	for(int i = n - 1; i >= 0; i--) {
		if(lastOcc[j][t[i] - 'a'] == -1) {
			cout << -1 << "\n";
			return;
		}
		prv[i] = i - lastOcc[j][t[i] - 'a'];
		j = lastOcc[j][t[i] - 'a'];
		j = min(j, i - 1);
	}

	// for(auto i : prv)
	// 	cout << i << " ";
	// cout << "\n";
	
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, prv[i]);

	if(ans > k) {
		cout << -1 << "\n";
		return;
	}

	cout << ans << "\n";
	
	for(int step = 0; step < ans; step++) {
		string tmp = s;
		for(int i = 0; i < n; i++) {
			if(prv[i]) {
				tmp[i] = s[i - 1];
				prv[i]--;
			} else{
				tmp[i] = s[i];
			}
		}
		// for(auto i : prv)
		// 	cout << i << " ";
		// cout << "\n";
		cout << tmp << "\n";
		s = tmp;
	}
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
