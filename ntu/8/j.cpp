
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
	int n, L; cin >> n >> L;

	vector <int> d(n, 0);
	int highest = 0;

	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());

	int prv = d[0], cnt = 0;
	for(int i = 1; i < n; i++) {
		if(d[i] - prv < L) {
			cnt++;
		} else {
			prv = d[i];
		}
	}

	cout << cnt << "\n";
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
