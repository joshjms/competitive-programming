
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, a[200005];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	bool has[n + 1];
	memset(has, 0, sizeof(has));
	for(int i = 1; i <= n; i++) {
		if(a[i]) has[a[i]] = 1;
	}

	vector <int> noHas;
	for(int i = 1; i <= n; i++)
		if(!has[i])
			noHas.pb(i);

	for(int i = 1; i <= n; i++) {
		if(a[i] == 0) {
			int b = noHas.back();
			a[i] = b;
			noHas.pop_back();
		}
	}

	int L = 1, R = n;
	for(int i = 1; i <= n; i++) {
		if(a[i] == i) {
			L++;
		} else break;
	}

	for(int i = n; i >= 1; i--) {
		if(a[i] == i) {
			R--;
		} else break;
	}

	int ans = max(0ll, R - L + 1);
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
