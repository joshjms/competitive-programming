
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
	int a, b, s, p, v;
	cin >> a >> b >> s >> p >> v;
	if (s == v) return void(cout << 0 << "\n");
	auto fpow = [&](int x, int k) {
		int ret = 1;
		while (k) {
			if (k & 1) ret = ret * x % p;
			x = x * x % p;
			k >>= 1;
		}
		return ret;
	};
	auto inv = [&](int x) {
		return fpow(x, p - 2);
	};
	if (a == 1) {
		int ans = (v - s + p) % p * inv(b) % p;
		cout << ans << "\n";
		return;
	}
	int A = (a * v - v + b) % p;
	int B = (a * s - s + b) % p;
	int x = A * inv(B) % p;
	auto modLog = [](int a, int b, int m) {
		int n = (int) sqrt(m) + 1, e = 1, f = 1, j = 1;
		unordered_map<int, int> A;
		while (j <= n && (e = f = e * a % m) != b % m)
		A[e * b % m] = j++;
		if (e == b % m) return j;
		if (__gcd(m, e) == __gcd(m, b))
		for (int i = 2; i < n + 1; i++) if (A.count(e = e * f % m)) return n * i - A[e];
		return -1ll;
	};
	int ans = modLog(a, x, p);
	if (ans == -1) cout << "IMPOSSIBLE" << "\n";
	else cout << ans << "\n";
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
