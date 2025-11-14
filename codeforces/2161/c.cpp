
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
	int n, x; cin >> n >> x;

	vector <int> a(n + 5, 0);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a.begin() + 1, a.begin() + n + 1);

	int l = 1, r = n, m = 0;
	int maxi = 0;
	vector <int> ans;
	for(int i = 1; i <= n; i++) {
		while(r >= i && (m + a[r]) >= x) {
			ans.pb(a[r]);
			maxi += a[r];
			(m += a[r]) %= x;
			r--;
		}
		if(i > r) break;
		(m += a[i]) %= x;
		ans.pb(a[i]);
	}

	cout << maxi << "\n";
	for(auto i : ans)
		cout << i << " ";
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
