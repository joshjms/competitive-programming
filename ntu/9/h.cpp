
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
	int n;
	cin >> n;
	set<string> s;
	auto ask = [&](char c, int x) {
		cout << "query " << c << " " << x << endl;
		cout.flush();
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++) {
			string ss;
			cin >> ss;
			s.insert(ss);
		}
		return cnt;
	};
	int cntt = 0;
	for (int i = 0; i < 26; i++) {
		if(n == 0) break;
		char c = char(i + 'a');

		vector<int> v;
		int tmp = n;
		if (n <= 30) v.pb(n);
		while (tmp > 30) {
			v.pb(tmp);
			if(tmp == 1) break;
			tmp = (tmp + 1) / 2;
		}
		reverse(v.begin(), v.end());
		int x;
		assert(v.size() > 0);
		for (auto j : v) {
			assert(j != 0);
			x = ask(c, j);
			cntt += j;
			if (x < j) break;
		}
		n -= x;
	}
	assert(cntt <= 3800);
	cout << "answer ";
	for (auto i : s) cout << i << " ";
	cout << "\n";
	cout.flush();
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
