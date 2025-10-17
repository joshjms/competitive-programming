
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n;

void solve() {
	cin >> n;

	int a[2 * n + 5];
	memset(a, 0, sizeof(a));

	a[1] = n;
	a[n + 1] = n;

	for(int i = 2; i <= n; i++) {
		int j = n - i + 1;
		a[i] = j;
		a[i + j * 2] = j;
	}

	for(int i = 1; i <= 2 * n; i++) {
		cout << a[i] << " ";
	}
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
