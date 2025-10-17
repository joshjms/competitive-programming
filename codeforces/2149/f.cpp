
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
	int h, d;
	cin >> h >> d;

	int ans = 0;
	if(h == 1) h++, ans++;

	int dist = 0;

	int l = 0, r = d - 1, waits = -1;
	while(l <= r) {
		int mid = (l + r) / 2;

		int bigSegment = d/(mid + 1) + 1;
		int smallSegment = d / (mid + 1);

		int bigCount = d % (mid + 1);
		int smallCount = (mid + 1) - bigCount;

		// debug(bigSegment);
		// debug(smallSegment);
		// debug(bigCount);
		// debug(smallCount);

		int sum = (bigSegment * (bigSegment + 1) / 2) * bigCount + (smallSegment * (smallSegment + 1) / 2) * smallCount;
		
		// debug(mid);
		// debug(sum);

		if(h + mid - sum > 0) {
			waits = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << d + waits + ans << "\n";
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
