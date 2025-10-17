
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, a[105];

void solve() {
	cin >> n;
	int cnt[n + 5];
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int x = 0;
		for(int j = 1; j <= n; j++) {
			if(cnt[j] >= i) {
				x++;
			}
		}
		ans = max(ans, x * i);
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
