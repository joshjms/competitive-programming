
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int primeFactors[200010];

void solve() {
	int n; cin >> n;
	vector <pair<int,int>> a(n + 5, {0, 0});

	multiset <int> st;

	for(int i = 1; i <= n; i++)
		cin >> a[i].se;
	for(int i = 1; i <= n; i++)
		cin >> a[i].fi;

	bool hasCommonFactor = false;
	for(int i = 1; i <= n; i++) {
		int tmp = a[i].se;

		while(tmp > 1) {
			int f = primeFactors[tmp];
			if(st.count(f)) hasCommonFactor = true;
			st.insert(f);
			while(tmp % f == 0) {
				tmp /= f;
			}
		}
	}

	if(hasCommonFactor) {
		cout << 0 << "\n";
		return;
	}

	sort(a.begin() + 1, a.begin() + n + 1);

	int _a = a[1].fi;
	int _b = a[2].fi;
	
	int ans = _a + _b;

	for(int i = 1; i <= n; i++) {
		int v = a[i].se;
		while(v > 1) {
			int f = primeFactors[v];
			assert(f != 0);
			auto it = st.find(f);
			if(it != st.end()) {
				st.erase(it);
			}
			while(v % f == 0) v /= f;
		}

		int x = a[i].se + 1;
		while(x > 1) {
			int f = primeFactors[x];
			assert(f != 0);
			auto it = st.find(f);
			if(it != st.end()) {
				ans = min(ans, a[i].fi);
			}
			while(x % f == 0) x /= f;
		}

		v = a[i].se;
		while(v > 1) {
			int f = primeFactors[v];
			assert(f != 0);
			st.insert(f);
			while(v % f == 0) v /= f;
		}
	}

	if(_a != _b) {
		set <int> fcts;

		for(int i = 1; i <= n; i++) {
			if(a[i].fi == _a) continue;
			int v = a[i].se;
			while(v > 1) {
				int f = primeFactors[v];
				assert(f != 0);
				fcts.insert(f);
				while(v % f == 0) v /= f;
			}
		}
		
		vector <int> vFct;

		for(auto i : fcts)
			vFct.pb(i);

		for(int i = 1; i <= n; i++) {
			if(a[i].fi != _a) continue;

			int need = 1e9;
			for(auto j : vFct) {
				assert(j != 0);
				int m = j - (a[i].se % j);
				need = min(need, m);
			}

			ans = min(ans, _a * need);
		}
	}

	cout << ans << "\n";
	
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	primeFactors[0] = 0;
	primeFactors[1] = 1;

	for(int i = 2; i <= 200005; i++) {
		if(primeFactors[i]) continue;
		primeFactors[i] = i;
		for(int j = i * i; j <= 200005; j += i) {
			primeFactors[j] = i;
		}
	}

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
