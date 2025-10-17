
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

	for(int k = 2; k / 2 <= n; k *= 2) {
		for(int j = 1; j <= n; j += k) {
			vector <int> a, b;

			for(int i = j; i < min(n + 1, j + k / 2); i++) a.pb(i);
			for(int i = j + k / 2; i < min(n + 1, j + k); i++) b.pb(i);

			// for(auto i : a)
			// 	cout << i << " ";
			// cout << endl;

			// for(auto i : b)
			// 	cout << i << " ";
			// cout << endl;

			for(auto ii : a) {
				for(auto jj : b) {
					cout << ii << " " << jj << endl;
					cout.flush();

					int resp = 0;
					cin >> resp;

					if(resp) {
						return;
					}
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
