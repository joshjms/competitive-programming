
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

	bool hasB = false;

	vector <char> s(n + 5);
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		if(s[i] == 'B') hasB = true;
	}

	vector <int> Q(q + 5);
	for(int i = 1; i <= q; i++)
		cin >> Q[i];

	if(!hasB) {
		for(int i = 1; i <= q; i++)
			cout << Q[i] << "\n";
		return;
	}

	for(int i = 1; i <= q; i++) {
		int v = Q[i];

		int cur = 1, ans = 0;
		while(v) {
			if(s[cur] == 'A') {
				v--;
				cur++;
				if(cur > n) cur = 1;
				ans++;
			} else {
				v /= 2;
				cur++;
				if(cur > n) cur = 1;
				ans++;
			}
		}

		cout << ans << "\n";
	}
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
