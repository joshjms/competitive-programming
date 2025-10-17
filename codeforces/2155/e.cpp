
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
	int n, m, k;
	cin >> n >> m >> k;

	int tokens[m + 1];
	memset(tokens, 0, sizeof(tokens));

	for(int i = 1; i <= k; i++) {
		int x, y; cin >> x >> y;
		tokens[y]++;
	}

	if(k == tokens[1]) {
		cout << "Yuyu\n";
		return;
	}

	if(n == 1) {
		// can just continuously delete from col 2
		cout << (tokens[2] % 2 == 1 ? "Mimo\n" : "Yuyu\n");
		return;
	}

	for(int i = 2; i <= m; i++) {
		if(tokens[i] % 2) {
			cout << "Mimo\n";
			return;
		}
	}

	cout << "Yuyu\n";
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
