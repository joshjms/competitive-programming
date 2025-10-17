
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int k, j, n;
int ab, ba;
int dp[1000005];

void solve() {
	cin >> k >> j >> n;

	ab = -1;
	while(ab % j && ab <= n) ab += k;
	ba = -1;
	while(ba % k && ba <= n) ba += j;

	int firstCollision = (k * j) / gcd(k, j);

	if(firstCollision > n) {
		cout << n / k + n / j << "\n";
		return;
	}

	for(int i = 1; i <= n; i++)
		dp[i] = 1e18;

	dp[firstCollision] = firstCollision / k + firstCollision / j;
	
	for(int i = 1; i < n; i++) {
		if(dp[i] == 1e18) continue;

		if(i + ab <= n) {
			dp[i + ab] = min(dp[i + ab], dp[i] + (ab + 1) / k + ab / j);
		} else {
			dp[n] = min(dp[n], dp[i] + (n - i + 1) / k + (n - i) / j);
		}

		if(i + ba <= n) {
			dp[i + ba] = min(dp[i + ba], dp[i] + (ba + 1) / j + ba / k);
		} else {
			dp[n] = min(dp[n], dp[i] + (n - i) / k + (n - i + 1) / j);
		}
	}
	
	// for(int i = 1; i <= n; i++)
	// 	cout << dp[i] << " ";
	// cout << "\n";

	cout << dp[n] << "\n";
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
