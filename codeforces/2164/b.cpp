
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

	int _even = 0;

	for(int i = 1; i <= n; i++) {
		if(a[i] % 2 == 0) {
			if(_even) {
				cout << _even << " " << a[i] << "\n";
				return;
			}
			_even = a[i];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= min(j + 100, n); j++) {
			if((a[j] % a[i]) % 2 == 0) {
				cout << a[i] << " " << a[j] << "\n";
				return;
			}
		}
	}
	
	cout << -1 << "\n";
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
