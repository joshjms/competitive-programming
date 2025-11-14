
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
	int n, k, x; cin >> n >> k >> x;

	vector <int> a(n + 1);

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a.begin() + 1, a.begin() + n + 1);
	
	int l = 1, r = x, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;

		vector <pair<int,int>> vp;

		vp.pb({-1, -1});
		for(int i = 1; i <= n; i++) {
			vp.pb({max(0ll, a[i] - mid + 1), min(x, a[i] + mid - 1)});
		}
		vp.pb({x + 1, x + 1});

		int tot = 0;
		int vps = vp.size();
		for(int i = 0; i < vps - 1; i++) {
			int range = max(0ll, vp[i + 1].fi - vp[i].se - 1);
			tot += range;
		}

		if(tot >= k) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	// cout << ans << "\n";

	if(ans == 0) {
		for(int i = 0; i < k; i++)
			cout << i << " ";
		cout << "\n";
		return;
	}

	vector <pair<int,int>> vp;
	vp.pb({-1, -1});
	for(int i = 1; i <= n; i++) {
		vp.pb({max(0ll, a[i] - ans + 1), min(x, a[i] + ans - 1)});
	}
	vp.pb({x + 1, x + 1});

	int tot = 0;
	int vps = vp.size();
	for(int i = 0; i < vps - 1 && k; i++) {
		int range = max(0ll, vp[i + 1].fi - vp[i].se - 1);

		for(int j = vp[i].se + 1; j < vp[i + 1].fi && k; j++) {
			cout << j << " ";
			k--;
		}

	}

	cout << "\n";
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
