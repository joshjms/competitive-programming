
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;


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

vector <int> gauss(vector<vector<int>> A, vector<int> b) {
	int n = A.size();
	for(int i = 1; i < n; i++) {
		A[i].pb(b[i]);
	}

	int row = 1, col = 1;
	vector <int> where(n, -1);
	while(row < n && col < n) {
		int sel = row;
		for(int i = row; i < n; i++) {
			if(A[i][col]) {
				sel = i;
				break;
			}
		}
		if(A[sel][col] == 0) {
			col++;
			continue;
		}
		swap(A[sel], A[row]);
		where[col] = row;

		int invPiv = inv(A[row][col]);
		for(int j = col; j <= n; j++)
			A[row][j] = A[row][j] * invPiv % mod;

		for(int i = 0; i < n; i++) {
			if(i != row && A[i][col]) {
				int f = A[i][col];
				for(int j = col; j <= n; j++) {
					A[i][j] = ((A[i][j] - f * A[row][j]) % mod + mod) % mod;
				}
			}
		}
		
		row++; col++;
	}

	vector <int> x(n, 0);

    for (int j = 1; j < n; ++j)
        if (where[j] != -1) x[j] = A[where[j]][n];

    for (int i = 1; i < n; ++i){
        long long s = 0;
        for (int j = 0; j < n; ++j) s = (s + A[i][j] * x[j]) % mod;
        if (s != A[i][n]) { /* no solution */ }
    }
    return x;
}

void solve() {
	int n, m; cin >> n >> m;
	vector <int> g[n + 1];

	vector <vector<int>> a(n, vector<int>(n));

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
	}

	for(int k = 1; k < n; k++) {
		for(int i = 0; i < n; i++) {
			a[k][i] = modex(k, i);
		}
	}

	vector <int> b(n);

	for(int k = 1; k < n; k++) {
		cout << "? " << 1 << " " << n << " " << k << "\n";
		cout.flush();
		
		cin >> b[k];
	}

	// for(int i = 1; i < n; i++) {
	// 	for(int j = 1; j < n; j++) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << b[i] << "\n";
	// }

	vector <int> res = gauss(a, b);
	// for(auto i : res)
	// 	cout << i << " ";
	// cout << "\n";

	cout << "!\n";
	cout.flush();

	int k; cin >> k;

	int ans = 0, cur = k;
	for(int i = 1; i < n; i++) {
		(ans += (res[i] * cur) % mod) %= mod;
		cur = (cur * k) % mod;
	}

	cout << ans << "\n";
	cout.flush();
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
