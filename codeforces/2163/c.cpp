
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
	vector <int> a(n + 5), b(n + 5);

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];

	vector <int> pm(n + 5, 0), sm(n + 5, 0), pmm(n + 5, 1e18), smm(n + 5, 1e18);
	vector <int> lastMin(2 * n + 5, 0), lastMinn(2 * n + 5, n + 1), lastMax(2 * n + 5, 0), lastMaxx(2 * n + 5, n + 1);
	for(int i = 1; i <= n; i++) {
		pm[i] = max(pm[i - 1], a[i]);
		lastMax[pm[i]] = i;
		pmm[i] = min(pmm[i - 1], a[i]);
		lastMin[pmm[i]] = i;
	}
	for(int i = n; i >= 1; i--) {
		sm[i] = max(sm[i + 1], b[i]);
		lastMaxx[sm[i]] = i;
		smm[i] = min(smm[i + 1], b[i]);
		lastMinn[smm[i]] = i;
	}

	for(int i = 1; i <= 2 * n; i++) {
		if(lastMax[i] == 0) {
			lastMax[i] = lastMax[i - 1];
		}
		if(lastMaxx[i] == n + 1) {
			lastMaxx[i] = lastMaxx[i - 1];
		}
	}

	for(int i = 2 * n; i >= 1; i--) {
		if(lastMin[i] == 0) {
			lastMin[i] = lastMin[i + 1];
		}
		if(lastMinn[i] == n + 1) {
			lastMinn[i] = lastMinn[i + 1];
		}
	}

	// for(int i = 1; i <= n; i++)
	// 	cout << pmm[i] << " ";
	// cout << "\n";

	// for(int i = 1; i <= 2 * n; i++)
	// 	cout << lastMax[i] << " ";
	// cout << "\n";

	// for(int i = 1; i <= 2 * n; i++)
	// 	cout << lastMaxx[i] << " ";
	// cout << "\n";

	// for(int i = 1; i <= 2 * n; i++)
	// 	cout << lastMin[i] << " ";
	// cout << "\n";

	// for(int i = 1; i <= 2 * n; i++)
	// 	cout << lastMinn[i] << " ";
	// cout << "\n";

	vector <int> usingR(2 * n + 5, 0);

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int l = min(pmm[i], smm[i]);
		int r = max(pm[i], sm[i]);
		usingR[r] = max(usingR[r], l);
	}

	for(int i = 1; i <= 2 * n; i++) {
		usingR[i] = max(usingR[i], usingR[i - 1]);
		ans += usingR[i];
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
