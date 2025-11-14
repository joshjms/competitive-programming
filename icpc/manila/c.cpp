
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
	int n, k; cin >> n >> k;
	vector <int> a(n + 5);
	vector <int> occ[n + 5];
	unordered_map <int,int> cnt;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	while(k) {
		bool same = true;
		for(auto i : cnt) {
			if(i.fi != i.se) {
				same = false;
				break;
			}
		}

		if(same) {
			break;
		}

		for(int i = 1; i <= n; i++)
			a[i] = cnt[a[i]];

		cnt.clear();
		for(int i = 1; i <= n; i++)
			cnt[a[i]]++;

		k--;
	}

	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << "\n";
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
