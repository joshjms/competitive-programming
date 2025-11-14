
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

	pair<int,int> b = {k - 1, 1};

	if(n < k) {
		cout << n << "\n";
		return;
	}

	if(k == 1) {
		cout << n << "\n";
		return;
	}

	int sum = k - 1, tmr = 0;
	while(true) {
		int x = k - 1 - ceil(1.0 * b.fi / b.se);
		
		for(int i = x - 5; i <= x + 5; i++) {
			ld comp1 = ceil((ld)1.0 * (ld)((ld)b.fi + (ld)i * (ld)b.se) / (k - 1));
			ld comp2 = (ld) b.se;

			if(comp1 > comp2) {
				x = i;
				break;
			}
		}

		if(sum + x * b.se >= n) {
			int y = (n - sum) / b.se; 
			cout << b.fi + y * b.se << "\n";
			return;
		}

		pair <int,int> nb = {b.fi + x * b.se, ceil(1.0 * (b.fi + x * b.se) / (k - 1))};

		sum += x * b.se;
		// debug(sum);
		// if(sum >= n) {
		// 	cout << nb.fi << "\n";
		// 	return;
		// }

		b = nb;

		++tmr;
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
