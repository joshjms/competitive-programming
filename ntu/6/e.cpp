
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
	string s, t;
	cin >> s;
	t = "";

	int sign = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			if(sign) {
				t += '+';
				if(s[i] != '0')
					sign = 0;
			}
			t += s[i];
		} else {
			if(s[i] == '-') {
				sign = 1;

				if(t.back() == '+' || t.back() == '-') t.pop_back();
				t += s[i];
				t += s[i + 1];
				i++;
			} else if(s[i] == '+') {
				sign = 0;
				if(t.back() == '+' || t.back() == '-') t.pop_back();
				t += s[i];
			}
		}
	}

	cout << t << "\n";
}

int32_t main() {
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);

	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
