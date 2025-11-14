
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
	// code here
	int a, b, c, d; cin >> a >> b >> c >> d;

	int l, r;

	if(a >= c && b <= d) {
		l = a;
		r = b;
	} else if(c >= a && d <= b) {
		l = c;
		r = d;
	} else if(c >= a && c <= b && b <= d) {
		l = c;
		r = b;
	} else if(a >= c && a <= d && b >= d) {
		l = a;
		r = d;
	} else {
		cout << 0 << "\n";
		return;
	}

	cout << r - l << "\n";
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
