
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
	cout.flush();
	int n; cin >> n;
	if(n == -1) {
		exit(1);
	}

	vector <int> decreasing;

	bool used[n * n + 1];
	memset(used, 0, sizeof(used));
	for(int q = 1; q <= n; q++) {
		vector <int> query;
		for(int i = 1; i <= n * n + 1; i++) {
			if(!used[i]) {
				query.pb(i);
			}
		}

		cout << "? " << query.size();
		for(int i = 0; i < query.size(); i++) {
			cout << " " << query[i];
		}
		cout << "\n" << flush;

		int c;
		cin >> c;
		if(c == -1) {
			exit(1);
		}
		int a[c + 1];
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= c; i++)
			cin >> a[i];

		for(int i = 1; i <= c; i++) 
			used[a[i]] = true;
		decreasing.pb(a[c]);
		
		// cout << "!";
		// for(int i = 1; i <= n + 1; i++) {
		// 	cout << " " << i;
		// }
		// cout << "\n" << flush;

		if(c >= n + 1) {
			cout << "!";
			for(int i = 1; i <= n + 1; i++) {
				cout << " " << a[i];
			}
			cout << "\n" << flush;
			return;
		}
	}

	assert(decreasing.size() >= n);
	vector <int> ans;

	for(int i = 0; i < decreasing.size(); i++) {
		if(i > n + 1) break;
		ans.pb(decreasing[i]);
	}

	if(decreasing.size() == n) {
		for(int i = 1; i <= n * n + 1; i++) {
			if(!used[i]) {
				ans.pb(i);
				break;
			}
		}
	}

	cout << "!";
	for(int i = 0; i < ans.size(); i++) {
		cout << " " << ans[i];
	}
	cout << "\n" << flush;
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
