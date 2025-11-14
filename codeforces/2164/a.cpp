
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
	vector <int> a(n + 5);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int x; cin >> x;

	int mini = 1e18;
	int maxi = -1e18;

	for(int i = 1; i <= n; i++) {
		mini = min(mini, a[i]);
		maxi = max(maxi, a[i]);
	}

	if(x >= mini && x <= maxi) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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
