
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
	int n, k; cin >> n >> k;
	vector <int> a(n + 5);

	int cnt[n + 5], ps[n + 5];
	memset(cnt, 0, sizeof(cnt));
	memset(ps, 0, sizeof(ps));

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	for(int i = n; i >= 1; i--) {
		ps[i] = ps[i + 1] + cnt[i];
	}

	int ans = 1;
	for(int i = 1; i <= n; i++) {
		int can = 0;
		if(4 * i <= n) can += ps[4 * i];
		if(3 * i <= n) can += cnt[3 * i];
		if(2 * i <= n) can += cnt[2 * i];
		if(i <= n) can += cnt[i];
		
		if(can + k >= n) {
			ans = i;
		}
	}

	cout << ans << "\n";
	
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
