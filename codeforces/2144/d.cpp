
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, y, c[200005];
int maxX[200005];
map <int,int> mp;

void solve() {
	mp.clear();

	cin >> n >> y;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		mp[c[i]]++;
	}
	
	sort(c + 1, c + n + 1);

	int worst = 0;
	map <int,int> use;
	for(int i = 1; i <= n; i++) {
		int ci = (c[i] + 1) / 2;
		if(use[ci] < mp[ci]) {
			use[ci]++;
		} else {
			worst -= y;
		}
		worst += ci;
	}

	for(int i = 1; i <= n; i++) {
		int normal = (c[i] + 1) / 2 - y;
		maxX[i] = c[i] / normal;
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
