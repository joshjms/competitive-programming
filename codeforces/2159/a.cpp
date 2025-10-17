
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
	int a[2 * n + 5];
	memset(a, 0, sizeof(a));

	vector <int> v;
	v.pb(1);

	for(int i = 2; i <= 2 * n; i++) {
		v.pb(i);
		cout << "? " << v.size() << " ";
		for(auto j : v)
			cout << j << " ";
		cout << "\n";
		cout.flush();

		int mad; cin >> mad;
		if(mad == 0) continue;

		a[i] = mad;
		v.pop_back();
	}

	vector <int> nv;
	for(int i = 1; i <= 2 * n; i++) {
		if(a[i] != 0) nv.pb(i);
	}

	for(int i = 1; i <= 2 * n; i++) {
		if(a[i] == 0) {
			nv.push_back(i);
			cout << "? " << nv.size() << " ";
			for(auto j : nv)
				cout << j << " ";
			cout << "\n";
			cout.flush();

			int mad; cin >> mad;
			a[i] = mad;
			nv.pop_back();
		}
	}

	cout << "! ";
	for(int i = 1; i <= 2 * n; i++)
		cout << a[i] << " ";
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
