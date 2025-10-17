
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int W, ans;
vector <pair<int,int>> V;

void dfsInput(int par) {
	int x, y;
	cin >> x >> y;

	V.pb({x, par});
	int u = V.size() - 1;

	for(int i = 1; i <= y; i++) {
		dfsInput(u);
	}
}

vector <int> g[100005];

void dfs(int u, int par) {
	for(auto v : g[u]) {
		dfs(v, u);
	}

	vector <int> tmp;
	for(auto v : g[u]) {
		tmp.pb(V[v].first);
	}

	sort(tmp.begin(), tmp.end());

	int sumPrefix = 0, i = 0;
	while(i < tmp.size() && sumPrefix + tmp[i] <= W) {
		sumPrefix += tmp[i];
		i++;
	}
	i--;

	int sum = V[u].fi;
	for(int j = 0; j <= i; j++) {
		sum += tmp[j];
	}
	ans += sum / W;
	sum %= W;
	V[u].fi = sum;

	ans += tmp.size() - (i + 1);
}

void solve() {
	cin >> W;

	dfsInput(-1);
	for(int i = 0; i < V.size(); i++) {
		if(V[i].se != -1) {
			g[V[i].se].pb(i);
		}
	}

	dfs(0, -1);

	if(V[0].fi) ans++;
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
