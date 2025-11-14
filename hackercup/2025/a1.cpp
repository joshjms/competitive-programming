
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve(int tc) {
	int n; cin >> n;
	vector <int> a(n + 5, 0);

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	int ans = 0;
	for(int i = 2; i <= n; i++)
		ans = max(ans, abs(a[i] - a[i - 1]));

	cout << "Case #" << tc << ": " << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
