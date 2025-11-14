
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
	int n; cin >> n;
	vector <int> p(n + 1, 0);
	vector <int> pos(n + 1, 0);

	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}

	for(int x = 1; x <= n * n; x++) {
		int i = x % n;
		if(i == 0) i = n;
		
		while(p[i] > 2) {
			// use this i as max
			int v = p[i];
			int j = pos[v - 1];
			int k = pos[v - 2];

			assert(j != i);
			assert(k != i);
			if(j < i || k < i) break;

			p[i] = v - 2;
			p[j] = v;
			p[k] = v - 1;

			pos[v - 2] = i;
			pos[v - 1] = k; 
			pos[v] = j;
		}
	}

	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << "\n";
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
