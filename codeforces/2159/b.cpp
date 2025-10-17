
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

	vector<vector<int>> tmp(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> a;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char c; cin >> c;
			tmp[i][j] = (c - '0');
		}
	}
	
	bool transpose = false;
	if(n > m) {
		swap(n, m);
		a.assign(n + 1, vector<int>(m + 1, 0));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				a[i][j] = tmp[j][i];
			}
		}
		transpose = true;
	} else {
		a.assign(n + 1, vector<int>(m + 1, 0));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				a[i][j] = tmp[i][j];
			}
		}
	}

	// nmsqrt(nm)?

	vector <pair<pair<int,int>, int>> rects[m + 1];

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int V = j - i + 1;
			vector <int> v;

			for(int k = 1; k <= m; k++) {
				if(a[i][k] && a[j][k]) {
					v.pb(k);
				}
			}

			int vs = v.size();

			for(int k = 0; k < vs - 1; k++) {
				int H = v[k + 1] - v[k] + 1;
				for(int ii = v[k]; ii <=  v[k + 1]; ii++) {
					rects[ii].pb({{i, j}, V * H});
				}
			}
		}
	}

	for(int i = 1; i <= m; i++) {
		sort(rects[i].begin(), rects[i].end());
	}

	vector <vector<int>> ans(n + 1, vector<int>(m + 1, 0));

	for(int i = 1; i <= m; i++) {
		priority_queue <pair<int,int>> pq;
		int idx = 0;

		for(int j = 1; j <= n; j++) {
			while(idx < rects[i].size() && rects[i][idx].fi.fi <= j) {
				pq.push({-rects[i][idx].se, rects[i][idx].fi.se});
				idx++;
			}

			while(!pq.empty() && pq.top().se < j) {
				pq.pop();
			}

			if(!pq.empty()) {
				ans[j][i] = -pq.top().fi;
			}
		}
	}

	if(transpose) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				cout << ans[j][i] << " ";
			}
			cout << "\n";
		}
	} else {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
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
