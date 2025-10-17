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
	int s, x;
	cin >> s >> x;

	vector <int> v;
	int u = s;
	while(gcd(u, x) != 1) u--;

	int tmp = u;

	u = s;
	while(gcd(u, x) != 1) u++;

	if(s - tmp < u - s) {
		cout << s - tmp + 1 << "\n";
		cout << tmp << " ";
		for(int i = 1; i <= s - tmp; i++) {
			cout << 1 << " ";
		}
		cout << "\n";
	} else {
		cout << u - s + 1 << "\n";
		cout << u << " ";
		for(int i = 1; i <= u - s; i++) {
			cout << -1 << " ";
		}
		cout << "\n";
	}

}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
