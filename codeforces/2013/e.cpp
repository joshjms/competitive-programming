
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

vector <int> pFct;

void solve() {
	int n; cin >> n;

	vector <int> a(n + 5);
	int g;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		g = (i == 1 ? a[i] : gcd(g, a[i]));
	}

	sort(a.begin() + 1, a.begin() + n + 1);
	for(int i = 1; i <= n; i++)
		a[i] /= g;

	vector <bool> vis(n + 5, 0);
	vis[1] = 1;

	int cur = a[1], ans = cur;
	for(int i = 2; i <= n; i++) {
		if(cur == 1) {
			ans++;
			continue;
		}

		pair <int,int> choose = {1e18, -1};

		for(int j = 1; j <= n; j++) {
			if(!vis[j]) {
				choose = min(choose, {gcd(a[j], cur), j});
			}
		}

		cur = choose.fi;
		ans += cur;
		vis[choose.se] = 1;
	}

	cout << ans * g << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	pFct.assign(100000, 0);
	for(int i = 2; i <= 100000; i++) {
		if(pFct[i] == 0) {
			pFct[i] = i;
			for(int j = i * i; j <= 100000; j += i) {
				pFct[j] = i;
			}
		}
	}

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
