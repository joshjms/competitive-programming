
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 1e9 + 7;

int fct[1000005];

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

int c(int n, int r) {
	int res = 1;
	for(int i = n; i > r; i--)
		res = (res * (i % mod)) % mod;
	res = (res * inv(fct[n - r])) % mod;
	return res;
}

int snb(int x, int n) {
	return c(x + n - 1, n - 1);
}

void solve(int tc) {
	int n, a, b; cin >> n >> a >> b;

	vector <int> facts;
	int f;

	for(int i = 1; i * i <= b; i++) {
		if(b % i == 0) {
			facts.pb(i);
			if(i != b / i) {
				facts.pb(b / i);
			}
		}
	}
	f = facts.size();
	sort(facts.begin(), facts.end());

	vector <pair<int,int>> pFacts[f];
	vector <int> allCnt(f, 1);

	for(int i = 0; i < f; i++) {
		int cur = facts[i];
		for(int j = 2; j * j <= cur; j++) {
			int cnt = 0;
			while(cur % j == 0) {
				cnt++;
				cur /= j;
			}
			if(cnt) pFacts[i].pb({j, cnt});
		}
		if(cur > 1) pFacts[i].pb({cur, 1});

		for(auto j : pFacts[i]) {
			(allCnt[i] *= snb(j.se, n)) %= mod;
		}
	}

	int ans = 0;
	for(int i = 0; i < f; i++) {
		if(facts[i] <= a) {
			(ans += (allCnt[i] * allCnt[f - i - 1]) % mod) %= mod;
		}
	}

	cout << "Case #" << tc << ": ";
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fct[0] = 1;
	for(int i = 1; i <= 1e6; i++)
		fct[i] = (fct[i - 1] * i) % mod;

	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
