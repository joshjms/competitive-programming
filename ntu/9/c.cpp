
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
	string s;
	cin >> s;

	int n = s.size();

	vector <int> v[2];
	bool vis[n];
	memset(vis, 0, sizeof(vis));

	for(int i = 2; i < s.size() - 2; i++) {
		if(s[i] != '+') {
			if(s[i - 2] == '+' && s[i + 2] == '+' && !vis[i - 2] && !vis[i - 1] && !vis[i] && !vis[i + 1] && !vis[i + 2]) {
				v[0].pb(i - 2);
				v[1].pb(i + 2);

				for(int j = i - 2; j <= i + 2; j++)
					vis[j] = 1;
			}
		}
	}

	for(int i = 2; i < s.size(); i++) {
		if(s[i] != '+' && !vis[i]) {
			if(s[i - 2] == '+' && !vis[i - 2] && !vis[i - 1]) {
				v[0].pb(i - 2);
				v[1].pb(i);

				for(int j = i - 2; j <= i; j++)
					vis[j] = 1;
			}
		} 
	}

	for(int i = 0; i < s.size() - 2; i++) {
		if(s[i] != '+' && !vis[i]) {
			if(s[i + 2] == '+' && !vis[i + 2] && !vis[i + 1]) {
				v[0].pb(i);
				v[1].pb(i + 2);

				for(int j = i; j <= i + 2; j++)
					vis[j] = 1;
			}
		} 
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	int i0 = 0, i1 = 0;
	for(int i = 0; i < s.size(); i++) {
		while(i0 < v[0].size() && v[0][i0] == i) {
			cout << "(";
			i0++;
		}
		cout << s[i];
		while(i1 < v[1].size() && v[1][i1] == i) {
			cout << ")";
			i1++;
		}
	}
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
