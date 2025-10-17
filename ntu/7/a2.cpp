
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;
const int N = 1e6;

void solve() {
	// code here
	vector<int> prime, lp(N);
	for (int i = 2; i < N; i++) {
		if (!lp[i]) lp[i] = i, prime.pb(i);
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] * i >= N) break;
			lp[prime[j] * i] = prime[j];
			if (prime[j] == lp[i]) break;
		}
	}
	int s, x;
	cin >> s >> x;
	if (gcd(s, x) == 1) return void(cout << 1 << "\n" << s);
	if (x & 1) {
		int p = 2;
		while (p <= 1e9) {
			if (gcd(abs(s - p), x) == 1) return void(cout << 2 << "\n" << p << " " << s - p);
			p *= 2;
		}
		assert(false);
	}
	else {
		if (s & 1) {
			s--;
			cout << 3 << "\n" << 1 << " ";
		}
		else cout << 2 << "\n";
		int p = 1;
		for (auto i : prime) {
			if (x % i) {
				p = i;
				break;
			}
		}
		// cout << "prime"
		// debug(p);
		int pp = p;
		while (pp <= 1e9) {
			// debug(s-pp);
			// debug(gcd(abs(s-pp),x));
			if (gcd(abs(s - pp), x) == 1) {
				// cout << "hi\n";
				return void(cout << pp << " " << s - pp);
			}
			pp *= p;
		}
		assert(false);
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
