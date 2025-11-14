
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
	vector <int> x(n + 1), y(n + 1);

	unordered_map <int, int> mp, cnt;

	for(int i = 1; i <= n; i++) 
		cin >> x[i] >> y[i];

	for(int i = 1; i <= n; i++) {
		mp[x[i] + y[i]]++;
		cnt[x[i]]++;
	}

	for(auto [i, X] : mp) {
		if(X % 2) {
			for(auto [j, Y] : cnt) {
				if(Y % 2) {
					cout << j << " " << i - j << "\n";
					return;
				}
			}
		}
	}
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
