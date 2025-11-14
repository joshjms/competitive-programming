
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
	int a, b;
	cin >> a >> b;

	if(a <= 50 && b <= 10) {
		cout << "White\n";
		return;
	} else if(b > 30) {
		cout << "Red\n";
		return;
	}

	cout << "Yellow\n";
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
