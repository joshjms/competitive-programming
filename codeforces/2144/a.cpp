
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, a[50], ps[50], ss[50];

void solve() {
	cin >> n;

	int sum = 0;
	memset(ps, 0, sizeof(ps));
	memset(ss, 0, sizeof(ss));

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= 3;

		(sum += a[i]) %= 3;
	}

	for(int i = 1; i <= n; i++) {
		ps[i] = (ps[i - 1] + a[i]) % 3;
	}
	
	for(int i = n; i >= 1; i--) {
		ss[i] = (ss[i + 1] + a[i]) % 3;
	}

	
	for(int l = 1; l < n; l++) {
		for(int r = l + 1; r < n; r++) {
			int prefix = ps[l];
			int suffix = ss[r + 1];
			int middle = (sum - (prefix + suffix) + 9) % 3;

			if(prefix != suffix && prefix != middle && suffix != middle) {
				cout << l << " " << r << "\n";
				return;
			}

			if(prefix == suffix && prefix == middle) {
				cout << l << " " << r << "\n";
				return;
			}
		}
	}

	cout << 0 << " " << 0 << "\n";
	
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
