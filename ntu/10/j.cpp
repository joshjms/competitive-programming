
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
	string s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	if (n == 2) return void(cout << "Alice" << "\n");
	vector<int> vis(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int j = i;
		cnt++;
		while (!vis[j]) {
			vis[j] = 1;
			j = a[j];
		}
	}
	if (n > 3) {
		if (s == "Bob") cout << "Bob\n";
		else {
			if (cnt != n - 1) cout << "Bob\n";
			else cout << "Alice\n";
		}
	}
	else {
		if (s == "Bob") {
			if (cnt == 1) cout << "Alice\n";
			else cout << "Bob\n";
		}
		else {
			if (cnt != n - 1) cout << "Bob\n";
			else cout << "Alice\n";
		}
	}
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
