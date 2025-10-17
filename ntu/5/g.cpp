
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int fact[1000005];

int modex(int a, int b) {
	if(b < 0) return 1;

	int res = 1;
	while(b) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

int inv(int x) {
	return modex(x, mod - 2);
}

int C(int n, int k) {
	return (((fact[n] * inv(fact[k])) % mod) * inv(fact[n - k])) % mod;
}

void solve() {
	int n;
	cin >> n;

	if(n % 2) {
		cout << 0 << "\n";
		return;
	}

	int tmp = fact[n];
	for(int i = 1; i <= n / 2; i++) {
		tmp = (tmp * inv(2)) % mod;
	}

	tmp = (tmp * inv(fact[n / 2])) % mod;
	int ans = tmp;
	// debug(ans);

	int res = modex(n / 2, n / 2 - 2);

	for(int i = 1; i < n / 2; i++) {
		(ans *= 4) %= mod;
	}
	
	cout << (ans * res) % mod << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for(int i = 1; i <= 1000000; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
