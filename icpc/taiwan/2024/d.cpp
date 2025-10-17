
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 1e9 + 7;

int modex(int a, int b) {
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

void solve() {

	// cout << (31 * inv(8)) % mod << "\n";

	int n, m, d0, d1, d2;
	cin >> n >> m >> d0 >> d1 >> d2;

	vector <vector<char>> a(n + 5, vector<char>(m + 5, '.'));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int poss = 0;
			int sum = 0;

			for(int k = 0; k < (1ll << 9); k++) {
				bool can = true;
				int c = 0;

				int maxi = 0;
				for(int ii = i - 1; ii <= i + 1; ii++) {
					for(int jj = j - 1; jj <= j + 1; jj++) {
						if(a[ii][jj] == '.' && (k & (1ll << c))) {
							can = false;
							break;
						}
						if(a[ii][jj] == 'V' && !(k & (1ll << c))) {
							can = false;
							break;
						}

						int dist = abs(ii - i) + abs(jj - j);

						if(k & (1ll << c)) {
							if(dist == 0) maxi = max(maxi, d0);
							else if(dist == 1) maxi = max(maxi, d1);
							else if(dist == 2) maxi = max(maxi, d2);
						}

						c++;
					}

					if(!can) break;
				}

				if(can) {
					poss++;
					sum += maxi;
				}
			}

			(ans += (sum * inv(poss) % mod)) %= mod;
		}
	}
	
	cout << ans << "\n";
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
