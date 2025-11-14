
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
	int n, q; cin >> n >> q;
	vector <pair<int,int>> ranges;
	for(int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;
		ranges.pb({l, r});
	}

	vector <int> lastR(n + 5, 0);
    vector<int> tmp(n + 5, 0);
    for (auto i : ranges) 
		tmp[i.fi] = max(tmp[i.fi], i.se);
    for (int i = 1; i <= n; i++) 
		lastR[i] = max(lastR[i - 1], tmp[i]);

	vector <int> pmex(n + 5, -1), smex(n + 5, -1);
	auto query = [&](int l, int r) {
		cout << "? " << l << " " << r << "\n";
		cout.flush();

		int resp; cin >> resp;
		return resp;
	};
	
	int l = 1, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;

		int ll = 1, rr = n, ii = -1;
		while(ll <= rr) {
			int mid2 = (ll + rr) / 2;
			int resp = (pmex[mid2] == -1 ? query(1, mid2) : pmex[mid2]);
			pmex[mid2] = resp;
			if(resp >= mid) {
				rr = mid2 - 1;
				ii = mid2;
			} else {
				ll = mid2 + 1;
			}
		}

		ll = 1, rr = n;
		int iii = -1;
		while(ll <= rr) {
			int mid2 = (ll + rr) / 2;
			int resp = (smex[mid2] == -1 ? query(mid2, n) : smex[mid2]);
			smex[mid2] = resp;
			if(resp >= mid) {
				ll = mid2 + 1;
				iii = mid2;
			} else {
				rr = mid2 - 1;
			}
		}

		if(ii == -1 || iii == -1) {
			r = mid - 1;
			continue;
		}

		if(lastR[iii] >= ii) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}

	cout << "! " << ans << "\n";
	cout.flush();
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
