
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, k;

void solve() {
	cin >> n >> k;
	int a[n + 1], b[k + 1];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= k; i++)
		cin >> b[i];

	sort(a + 1, a + n + 1, greater<int>());
	sort(b + 1, b + k + 1);

	int voucher = 1, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(voucher <= k) {
			int j = i + b[voucher] - 1;
			for(; i < j && i <= n; i++) {
				ans += a[i];
			}
			voucher++;
		} else {
			ans += a[i];
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
