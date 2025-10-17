
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
	string s;

	cin >> n >> s;

	int a[n + 1];

	for(int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
	}

	int ans[n + 1];
	memset(ans, -1, sizeof(ans));

	int l = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i]) {
			ans[i] = i;

			if((i - 1) - (l + 1) + 1 == 1) {
				cout << "NO\n";
				return;
			}

			vector <int> tmp;
			for(int j = i - 1; j >= l + 1; j--) {
				tmp.pb(j);
			}
			for(int j = l + 1; j < i; j++) {
				ans[j] = tmp[j - l - 1];
			}
			l = i;
		}
	}

	if(n - (l + 1) + 1 == 1) {
		cout << "NO\n";
		return;
	}

	vector <int> tmp;
	for(int j = n; j >= l + 1; j--) {
		tmp.pb(j);
	}
	for(int j = l + 1; j <= n; j++) {
		ans[j] = tmp[j - l - 1];
	}

	// for(int i = 1; i <= n; i++) {
	// 	cout << ans[i] << " ";
	// }
	// cout << "\n";

	cout << "YES\n";

	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
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
