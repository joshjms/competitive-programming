
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

	sort(a.begin() + 1, a.begin() + n + 1);

	for(int i = 2; i < n; i += 2) {
		if(a[i] != a[i + 1]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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
