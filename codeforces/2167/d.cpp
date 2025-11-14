
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
	vector <int> a(n + 1, 0);

	int g = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(!g) g = a[i];
		else g = gcd(g, a[i]);
	}

	for(int idx = 2; ; idx++) {
		if(gcd(g, idx) == 1) {
			cout << idx << "\n";
			return;
		}
	}

	assert(false);
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
