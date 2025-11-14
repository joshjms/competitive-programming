
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

bool solve() {
	int n; cin >> n;
	if(n == 0) return 1;
	
	vector <int> a(n + 5), b(n + 5);
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= n; i++)
		cin >> b[i];

	int ans = 0, last = 0, sa = 0, sb = 0;
	for(int i = 1; i <= n; i++) {
		sa += a[i];
		sb += b[i];
		if(sa > sb) {
			if(last == -1) ans++;
			last = 1;
		} else if(sa < sb) {
			if(last == 1) ans++;
			last = -1;
		}
	}

	cout << ans << "\n";

	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (true) {
		if(solve()) break;
	}

	return 0;
}
