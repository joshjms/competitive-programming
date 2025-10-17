
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

	int a[2 * n + 1];
	for(int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}

	int ans[n + 1];
	memset(ans, 0, sizeof(ans));

	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum -= a[i];
		a[i] *= -1;
	}
	for(int i = n + 1; i <= 2 * n; i++) {
		sum += a[i];
	}

	int ps[2 * n + 5], ss[2 * n + 5];
	memset(ps, 0, sizeof(ps));
	memset(ss, 0, sizeof(ss));

	for(int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + a[i];
	}

	for(int i = 2 * n; i >= n + 1; i--) {
		ss[i] = ss[i + 1] + a[i];
	}

	ans[n] = sum;

	int l = n, r = n + 1, cur = 0;
	for(int i = n - 1; i >= 1; i--) {
		cur += a[l] + a[r];
		cur *= -1;
		// debug(cur);
		ans[i] = ps[l - 1] + ss[r + 1] + cur;
		// debug(ps[l - 1]);
		// debug(ss[r + 1]);
		l--, r++;
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << "\n";
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
