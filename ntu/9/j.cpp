
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
	int n;
	cin >> n;
	vector<vector<int>> bet(n + 1, vector<int>(n + 1)), ori(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		bet[i][n - 1] = (1ll << (n + i + 1));
		bet[n - 1][i] = (1ll << (n + i + 1));
		ori[i][n - 1] = (1ll << (n + i + 1));
	}
	for (int i = 0; i < n; i++) ori[n - 1][i] = ((1ll << (n - i)) - 1) * (1ll << (n + i + 1));
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			bet[i][j] = (- ori[i][j + 1] + ori[i + 1][j]) / 2;
			ori[i][j] = (ori[i][j + 1] + ori[i + 1][j]) / 2;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << ori[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << bet[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	int w = 0, l = 0;
	while (w != n && l != n) {
		cout << bet[w][l] << endl;
		string res;
		cin >> res;
		if (res == "Won") w++;
		else l++;
	}
}

int32_t main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
