
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, m, q;
vector <pair<int,int>> g[100005], gg[100005];

priority_queue <pair<int,int>> pq, pq2;

int distNoRain[100005];
int distWithRain[100005];

pair <int,int> query[100005];
int ans[100005];

void solve() {
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++) {
		int u, v, w, z;
		cin >> u >> v >> w >> z;

		gg[u].pb({v, w});
		gg[v].pb({u, w});
		if(z == 2) {
			g[u].pb({v, w});
			g[v].pb({u, w});
		}
	}

	// for(int i = 1; i <= n; i++) {
	// 	for(auto j : gg[i]) 
	// 		cout << j.fi << " ";
	// 	cout << "\n";
	// }

	for(int i = 1; i <= n; i++) {
		distNoRain[i] = 1e18;
		distWithRain[i] = 1e18;
	}

	while(!pq.empty()) pq.pop();
	pq.push({0, 1});
	distNoRain[1] = 0;
	while(!pq.empty()) {
		int cur = pq.top().se;
		int dist = -pq.top().fi;

		pq.pop();

		if(dist != distNoRain[cur]) continue;

		for(auto nb : gg[cur]) if(distNoRain[nb.fi] > dist + nb.se) {
			distNoRain[nb.fi] = dist + nb.se;
			pq.push({-distNoRain[nb.fi], nb.fi});
		}
	}

	while(!pq.empty()) pq.pop();
		pq.push({0, n});
	distWithRain[n] = 0;
	while(!pq.empty()) {
		int cur = pq.top().se;
		int dist = -pq.top().fi;

		pq.pop();

		if(dist != distWithRain[cur]) continue;

		for(auto nb : g[cur]) if(distWithRain[nb.fi] > dist + nb.se) {
			distWithRain[nb.fi] = dist + nb.se;
			pq.push({-distWithRain[nb.fi], nb.fi});
		}
	}

	// for(int i = 1; i <= n; i++)
	// 	cout << distNoRain[i] << " ";
	// cout << "\n";

	// for(int i = 1; i <= n; i++)
	// 	cout << distWithRain[i] << " ";
	// cout << "\n";

	while(!pq2.empty()) pq2.pop();
	for(int i = 1; i <= n; i++) {
		pq2.push({-(distNoRain[i] + distWithRain[i]), distNoRain[i]});
	}

	cin >> q;
	for(int j = 1; j <= q; j++) {
		int t; cin >> t;
		query[j] = {-t, j};
	}
	sort(query + 1, query + q + 1);

	for(int j = 1; j <= q; j++) {
		int rainTime = -query[j].fi;
		int pos = query[j].se;

		while(!pq2.empty() && pq2.top().se > rainTime) {
			pq2.pop();
		}

		if(pq2.empty()) {
			ans[pos] = -1;
			continue;
		}

		ans[pos] = -pq2.top().fi;
	}

	for(int j = 1; j <= q; j++)
		cout << (ans[j] == 1e18 ? -1 : ans[j]) << "\n";
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
