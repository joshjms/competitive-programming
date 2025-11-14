
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
	string s, t; cin >> s >> t;

	int cnt[26];
	memset(cnt, 0, sizeof(cnt));

	for(auto i : s)
		cnt[i - 'a']++;
	for(auto i : t)
		cnt[i - 'a']--;

	for(int i = 0; i < 26; i++)
		if(cnt[i]) {
			cout << "NO\n";
			return;
		}

	cout << "YES\n";
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
