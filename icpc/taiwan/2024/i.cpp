
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n;
int a[20];
bool memo[101][(1ll << 17)];
vector <int> ans;

bool dp(int need, int mask) {
	if(mask == (1ll << (n - 1)) - 1) {
		ans.pb(need);
		return true;
	}

	for(int j = 0; j < (n - 1); j++) {
		if(!(mask & (1 << j)) && a[j] % need == 0 && a[j] / need <= 100) {
			int newMask = mask | (1 << j);
			if(!memo[a[j] / need][newMask]) {
				memo[a[j] / need][newMask] = 1;
				bool ret = dp(a[j] / need, newMask);
				if(ret) {
					ans.pb(need);
					return true;
				}
			}
		}
	}

	return false;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; i++)
		cin >> a[i];

	for(int i = 0; i < n - 1; i++) {
		for(int j = 1; j * j <= a[i]; j++) {
			if(a[i] % j == 0 && j <= 100 && a[i] / j <= 100) {
				int mask = (1ll << i);
				if(!memo[a[i] / j][mask]) {
					memo[a[i] / j][mask] = 1;
					int ret = dp(a[i] / j, mask);

					if(ret == 1) {
						ans.pb(j);
						reverse(ans.begin(), ans.end());
						cout << "Yes\n";
						for(auto x : ans)
							cout << x << " ";
						cout << "\n";

						return;
					}
				}
				if(!memo[j][mask]) {
					memo[j][mask] = 1;
					int ret = dp(j, mask);

					if(ret == 1) {
						ans.pb(a[i] / j);
						reverse(ans.begin(), ans.end());
						cout << "Yes\n";
						for(auto x : ans)
							cout << x << " ";
						cout << "\n";

						return;
					}
				}
			}
		}
	}

	cout << "No\n";
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
