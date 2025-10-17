
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, m, a[205];

void solve() {
	cin >> n >> m;

	bool ok = true;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
		if(i > 1 && a[i] - 1 != a[i - 1]) ok = false;
	}

	if(!ok) {
		cout << 1 << "\n";
		return;
	}

	int x = a[m];
	cout << n - x + 1 << "\n";

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
