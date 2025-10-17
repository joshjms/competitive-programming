
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
	string s; cin >> s;

	int n = s.size();

	vector <int> v(n);
	iota(v.begin(), v.end(), 0);

	int ans = 0;

	do {
		bool can = true;

		for(int i = 0; i < n; i++)
			if(v[i] == i) {
				can = false;
				break;
			}

		for(int i = 0; i < n; i++) {
			if(v[i] > i && s[v[i]] == '0') {
				can = false;
				break;
			}
		}

		if(can) ans++;
	} while(next_permutation(v.begin(), v.end()));

	debug(ans);
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
