
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

	int bigNumbers = 0;

	vector <int> a(n + 1);
	vector <int> cnt(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] > n) {
			bigNumbers++;
			continue;
		}
		cnt[a[i]]++;
	}

	vector <int> cover(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		if(cnt[i] == 0) continue;
		int coverUntil = max(1ll, i - cnt[i] + 1);

		for(int j = i; j >= coverUntil; j--) {
			cover[j]++;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += (cover[i] == 0 ? 1 : 0);
	}
	// debug(ans);

	// for(int i = 1; i <= n; i++)
	// 	cout << cover[i] << " ";
	// cout << "\n";

	int q; cin >> q;
	while(q--) {
		int x, y; cin >> x >> y;

		int origNum = a[x];
		if(origNum > n) bigNumbers--;
		else {
			int coverUntil = origNum - cnt[origNum] + 1;
			if(coverUntil > 0) {
				cover[coverUntil]--;
				if(cover[coverUntil] == 0) ans++;
			}
			cnt[origNum]--;
		}

		if(y > n) bigNumbers++;
		else {
			cnt[y]++;
			int coverUntil = y - cnt[y] + 1;
			if(coverUntil > 0) {
				if(cover[coverUntil] == 0) ans--;
				cover[coverUntil]++;
			}
		}
		a[x] = y;

		// for(int i = 1; i <= n; i++)
		// 	cout << cover[i] << " ";
		// cout << "\n";
		// debug(bigNumbers);

		cout << max(ans, bigNumbers) << "\n";
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
