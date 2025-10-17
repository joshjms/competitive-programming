
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

	vector <pair<int,int>> table;
	bool flag = 0;

	for(int t = 1; t <= n; t++) {
		int ai;
		if(!(cin >> ai)) {
			exit(0);
		}

		if(ai == 0 || flag) {
			cout << 0 << "\n";
			cout << "IGNORE\n";
			cout.flush();

			continue;
		}

		table.pb({ai, t});

		// for(auto i : table)
		// 	cout << i.fi << " " << i.se << "\n";

		vector <int> ignore;

		int tableSize = table.size();
		int dp[tableSize + 5][600];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;

		vector <int> keep;

		for(int i = 0; i < tableSize && !flag; i++) {
			for(int j = 0; j < 600 && !flag; j++) {
				if(dp[i][j] == -1) continue;
				
				if(dp[i + 1][j] == -1) {
					dp[i + 1][j] = dp[i][j];
				}

				if(j + table[i].fi < 600 && dp[i + 1][j + table[i].fi] == -1) {
					dp[i + 1][j + table[i].fi] = i;
				}

				if(j + table[i].fi >= 600 && j + table[i].fi <= 1000) {
					flag = 1;
					
					keep.pb(table[i].se);
					int cur = i;
					int curj = j;
					while(curj > 0) {
						int nxt = dp[cur][curj];
						keep.pb(table[nxt].se);
						curj -= table[nxt].fi;
						cur = nxt;
					}

					// cout << keep.size() << "\n";
					// for(auto i : keep) {
					// 	cout << i << " ";
					// }
					// cout << "\n";
					// cout.flush();

					break;
				}
			}
		}

		// debug(flag);
		
		if(flag) {
			vector <pair<int,int>> newTable;
			for(int i = 0; i < tableSize; i++) {
				bool found = 0;
				for(auto j : keep) {
					if(j == table[i].se) {
						found = 1;
						break;
					}
				}
				if(found) {
					newTable.pb(table[i]);
				} else {
					ignore.pb(table[i].se);
				}
			}

			table = newTable;
			
			cout << ignore.size() << " ";
			for(auto i : ignore) {
				cout << i << " ";
			}
			cout << "\n";

			cout << "TAKE\n";
			cout.flush();

			continue;
		}

		// for(auto i : table)
		// 	cout << i.fi << " " << i.se << "\n";
		// cout << "\n";

		int sum = 0;
		for(auto i : table) {
			sum += i.fi;
		}

		if(sum > 1000) {
			pair <int,int> maxi = {0, 0};
			for(auto i : table) {
				maxi = max(maxi, i);
			}

			if(ai == maxi.fi) {
				vector <pair<int,int>> newTable;
				for(auto i : table) {
					if(i.se != t) {
						newTable.pb(i);
					}
				}
				table = newTable;

				cout << 0 << "\n";
				cout << "IGNORE\n";
				cout.flush();

				continue;
			} else {
				cout << 1 << " ";
				cout << maxi.se << "\n";

				cout << "TAKE\n";
				cout.flush();

				vector <pair<int,int>> newTable;
				for(auto i : table) {
					if(i.se != maxi.se) {
						newTable.pb(i);
					}
				}
				table = newTable;

				continue;
			}
		} else {
			cout << 0 << "\n";
			cout << "TAKE\n";
			cout.flush();
		}
	}
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
