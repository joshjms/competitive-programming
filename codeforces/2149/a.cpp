
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

	int a[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int ans = 0, neg = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] < 0) neg++;
		if(a[i] == 0) ans++;
	}

	ans += (neg % 2) * 2;
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
