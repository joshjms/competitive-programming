
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
	int n, m;
	string s;

	cin >> n >> m;
	cin >> s;

	int a[m + 1];
	map <int, int> mp;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
		mp[a[i]] = 1;
	}

	int cur = 1;
	for(int i = 1; i <= n; i++) {
		if(s[i - 1] == 'A') {
			int ne = cur + 1;
			mp[ne] = 1;
			cur = ne;
		} else {
			int ne = cur + 1;
			while(mp[ne]) ne++;
			mp[ne] = 1;
			cur = ne;
			while(mp[cur]) cur++;
		}
	}

	vector <int> ans;

	for (auto [k, v] : mp) {
		if(!v) continue;
		ans.pb(k);
	}
	
	cout << ans.size() << "\n";
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
