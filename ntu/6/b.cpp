
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
	int b, w;
	cin >> b >> w;

	bool sw = 0;
	if(b > w) {
		sw = 1;
		swap(b, w);
	}

	vector <int> a[3];

	if(b < w) {
		b--;
		while(b < w) {
			a[0].pb(1);
			a[1].pb(0);
			a[2].pb(1);
			w--;
			a[0].pb(1);
			a[1].pb(1);
			a[2].pb(1);
		}
	}

	for(int i = 0; i < b; i++) {
		a[0].pb(0);
		a[1].pb(0);
		a[2].pb(0);
		a[0].pb(1);
		a[1].pb(1);
		a[2].pb(1);
	}

	cout << a[0].size() << " " << 3 << "\n";
	for(int i = 0; i < a[0].size(); i++) {
		for(int j = 0; j < 3; j++) {
			if(!sw)
				cout << (a[j][i] ? "@" : ".");
			else
				cout << (a[j][i] ? "." : "@");
		}
		cout << "\n";
	}
}

int32_t main() {
	freopen("black.in", "r", stdin);
	freopen("black.out", "w", stdout);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
