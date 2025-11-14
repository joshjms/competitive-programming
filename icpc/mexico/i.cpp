
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
	int n, m; cin >> n >> m;
	
	vector <int> a(n + 5), b(m + 5);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	
	vector <__int128_t> pa(n + 5, 0), pai(n + 5, 0);
	for(int i = 1; i <= n; i++) {
		pa[i] = pa[i - 1] + a[i];
		pai[i] = pai[i - 1] + a[i] * i;
	}
	
	__int128_t ans = 0;
	for(int j = 1; j <= m; j++) {
		ans += b[j] * pai[n];
	}

	for(int j = 1; j <= m; j++) {
		__int128_t bjj = b[j] * j;
		__int128_t as = 0;
		for(int k = 0; k <= n / j; k++) {
			int l = k * j;
			int r = l + j - 1;
			l = max(l, 1ll);
			r = min(r, n);
			as += k * (pa[r] - pa[l - 1]);
		}
		__int128_t prod = bjj * as;
		ans -= prod;
	}
	
    if (ans == 0) { cout << 0 << '\n'; return; }
    bool neg = ans < 0;
    if (neg) ans = -ans;
    string s;
    while (ans > 0) {
        int digit = (int)(ans % 10);
        s.push_back('0' + digit);
        ans /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    cout << s << '\n';
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
