
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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ax = 0, ay = sqrt(a);
	int bx, by, cx, cy, dx, dy;
	vector<pair<int, int>> answer;
	for (int i = sqrt(b/2); i <= sqrt(b);i++){
		int y = b - i * i;
		int z = sqrt(y);
		if (z * z == y) {
			answer.pb({i,z});
		}
	}
	// cout << bx << " " << by << "\n";
	auto dis = [&](int x, int y) {
		return x * x + y * y;
	};
	for (auto [x, y] : answer) {
		bx = x, by = y;
		
		for (int i = 0; i < 8; i++) {
			int xx = bx, yy = by;
			if ((i >> 2) & 1) swap(xx, yy);
			if ((i >> 1) & 1) xx *= -1;
			if (i & 1) yy *= -1;
			int dix = ax - xx, diy = ay - yy;
			dx = ax + diy;
			dy = ay - dix;
			cx = bx + diy;
			cy = by - dix;
			// cout << dx << " " << dy << "\n";
			// cout << dis(dx, dy) << "\n";
			// cout << cx << " " << cy << "\n";
			// cout << dis(cx, cy) << "\n";
			if (dis(dx, dy) == d && dis(cx, cy) == c) {
				cout << ay << " " << xx << " " << yy << " " << cx << " " << cy << " " << dx << " " << dy;
				return;
			}
			dx = ax - diy;
			dy = ay + dix;
			cx = bx - diy;
			cy = by + dix;
			if (dis(dx, dy) == d && dis(cx, cy) == c) {
				cout << ay << " " << xx << " " << yy << " " << cx << " " << cy << " " << dx << " " << dy;
				return;
			}
		}
		ay *= -1;
		for (int i = 0; i < 8; i++) {
			int xx = bx, yy = by;
			if ((i >> 2) & 1) swap(xx, yy);
			if ((i >> 1) & 1) xx *= -1;
			if (i & 1) yy *= -1;
			int dix = ax - xx, diy = ay - yy;
			dx = ax + diy;
			dy = ay - dix;
			cx = bx + diy;
			cy = by - dix;
			// cout << dx << " " << dy << "\n";
			// cout << dis(dx, dy) << "\n";
			// cout << cx << " " << cy << "\n";
			// cout << dis(cx, cy) << "\n";
			if (dis(dx, dy) == d && dis(cx, cy) == c) {
				cout << ay << " " << xx << " " << yy << " " << cx << " " << cy << " " << dx << " " << dy;
				return;
			}
			dx = ax - diy;
			dy = ay + dix;
			cx = bx - diy;
			cy = by + dix;
			if (dis(dx, dy) == d && dis(cx, cy) == c) {
				cout << ay << " " << xx << " " << yy << " " << cx << " " << cy << " " << dx << " " << dy;
				return;
			}
		}
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
