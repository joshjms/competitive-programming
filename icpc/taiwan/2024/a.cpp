
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
	vector <int> v;

	int highestPig = 0;

	for(int i = 1; i <= n; i++) {
		string name; cin >> name;
		int value; cin >> value;

		if(name == "pig") {
			highestPig = max(highestPig, value);
		} else {
			v.push_back(value);
		}
	}

	int ans = highestPig;

	for(int i = 0; i < v.size(); i++) {
		if(v[i] < highestPig) {
			ans += v[i];
		}
	}

	cout << ans << "\n";
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
