
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
	int n;
	cin >> n;
	int k = ceil((2.0 * sqrt(n)) / 3.0);
	cout << k << "\n";
	cout << 1 << " ";
	if (k >= 2) cout << 2 << " ";
	if (k >= 3) cout << 6 << " ";
	int now = 3, pre = 6, g = 2;
	k -= 3;
	while (k > 0) {
		int x = now * (now + 1);
		int y = now * (now + 2);
		int gx = gcd(x, pre), gy = gcd(y, pre);
		// cout << gx << " " << gy << "\n";
		if (g < min(gx, gy)) {
			if (gx <= gy){
				g = gx;
				cout << x << " ";
				pre = x;
				now++;
			}
			else {
				g = gy;
				cout << y << " ";
				pre = y;
				now += 2;	
			}
		}
		else if (g < gy) {
			g = gy;
			pre = y;
			cout << y << " ";
			now += 2;
		}
		else {
			g = gx;
			pre = x;
			cout << x << " ";
			now++;
		}
		// cout << 1ll * (2 * now + 1) * (2 * now + 3) << " ";
		// now++;
		k--;
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
