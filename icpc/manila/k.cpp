
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
	// code here
	string t1 = "QWERTYUIOP";
	string t2 = "ASDFGHJKL";
	string t3 = "ZXCVBNM";
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	set<char> c;
	for (int i = 0; i < s1.size(); i++) if (s1[i] == '*') c.insert(t1[i]);
	for (int i = 0; i < s2.size(); i++) if (s2[i] == '*') c.insert(t2[i]);
	for (int i = 0; i < s3.size(); i++) if (s3[i] == '*') c.insert(t3[i]);
	// for (auto i : c) cout << i << "\n";
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		bool ans = 1;
		set<char> cc;
		for (auto i : s) {
			if (!c.count(i)) ans = false;
			else cc.insert(i);
		}
		if (cc.size() != c.size()) ans = false;
		cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
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
