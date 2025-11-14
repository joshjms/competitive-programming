
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

	set <int> st;
	int cnt[15];
	memset(cnt, 0, sizeof(cnt));
	bool akarin[n + 5];
	memset(akarin, 0, sizeof(akarin));

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 15; j++) {
			if(i & (1ll << j)) {
				cnt[j]++;
			}
		}
	}

	// for(int i = 0; i < 15; i++)
	// 	cout << cnt[i] << " ";
	// cout << "\n";

	for(int i = 1; i < n; i++) {
		st.insert(i);
	}
	
	int ans = 0;
	for(int i = 0; i < 15; i++) {
		vector <int> poss;
		for(int j = 1; j <= n; j++) {
			if(!akarin[j]) poss.pb(j);

			// cout << akarin[j] << " ";
		}
		// cout << "\n";

		if(poss.size() == 1) {
			cout << "! " << poss[0] << "\n";
			cout.flush();
			return;
		}

		vector <int> hasBit, noBit;

		for(auto j : st) {
			cout << "? " << j << " " << (1ll << i) << "\n";
			cout.flush();

			int resp; cin >> resp;
			if(resp) hasBit.pb(j);
			else noBit.pb(j);
		}

		// debug(hasBit.size());
		// debug(noBit.size());
		// debug(cnt[i]);
		// cout.flush();
		
		if(hasBit.size() + 1 == cnt[i]) {
			// the last one has that bit
			ans += (1ll << i);
			for(auto j : noBit) st.erase(j);
			for(int j = 1; j <= n; j++) {
				if(!(j & (1ll << i)) && !akarin[j]) {
					akarin[j] = 1;
					for(int k = 0; k < 15; k++) {
						if(j & (1ll << k)) cnt[k]--;
					}
				}
			}
		} else if(noBit.size() + 1 == (st.size() + 1) - cnt[i]) {
			for(auto j : hasBit) st.erase(j);
			for(int j = 1; j <= n; j++) {
				if((j & (1ll << i)) && !akarin[j]) {
					akarin[j] = 1;
					for(int k = 0; k < 15; k++) {
						if(j & (1ll << k)) cnt[k]--;
					}
				}
			}
		} else {
			assert(false);
		}
	}

	vector <int> poss;
	for(int j = 1; j <= n; j++) {
		if(!akarin[j]) poss.pb(j);

		// cout << akarin[j] << " ";
	}
	// cout << "\n";

	if(poss.size() == 1) {
		cout << "! " << poss[0] << "\n";
		cout.flush();
		return;
	}

	assert(false);
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
