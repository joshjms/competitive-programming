
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void check(int n, int m) {int all = pow(m, n);
	int cnt = 0;
	
	for(int i = 0; i < all; i++) {
		vector<int> a(n);
		int tmp = i;
		for(int j = 0; j < n; j++) {
			a[j] = tmp % m;
			tmp /= m;
		}
		
		bool can = true;
		for(int j = 1; j < n; j++)
			if(a[j] == a[j - 1])
				can = false;

		if(!can) continue;

		int xorSum = 0;
		for(int j = 0; j < n; j++)
			xorSum ^= a[j];

		if(xorSum == 0) {
			cnt++;
		}
	}

	cout << cnt << "\n";
}

void solve() {
	for(int i = 1; i <= 12; i++)
		check(i, 4);
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
