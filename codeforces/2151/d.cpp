
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int fact[200005];

int modex(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}

	return res;
}

int inv(int x) {
	return modex(x, mod - 2);
}

int C(int x, int y) {
	return (((fact[x] * inv(fact[y])) % mod) * inv(fact[x - y])) % mod;
}

void solve() {
	int n;
	cin >> n;

	int a[n + 1], s = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}

	if(s != n) {
		cout << 0 << "\n";
		return;
	}

	int half = (n + 1) / 2;
	for(int i = half + 1; i <= n; i++)
		if(a[i]) {
			cout << 0 << "\n";
			return;
		}

	int ans = 1;
	int used = 0;

	for(int i = half; i >= 1; i--) {
		int col = n - 2 * (i - 1);
		int avail = col - used;
		int need = a[i];

		if(need < 0 || need > avail) {
			cout << 0 << "\n";
			return;
		}

		ans = (ans * C(avail, need)) % mod;
		used += need;
	}

	if(used != n) {
		cout << 0 << "\n";
		return;
	}

	cout << ans % mod << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for(int i = 1; i <= 200000; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
