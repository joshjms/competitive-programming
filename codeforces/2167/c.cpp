
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
	vector <int> a(n + 1);

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector <int> cnt(2, 0);

	for(int i = 1; i <= n; i++) {
		cnt[a[i] % 2]++;
	}

	if(!cnt[0] || !cnt[1]) {
		for(int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << "\n";

		return;
	}

	sort(a.begin() + 1, a.begin() + n + 1);
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
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
