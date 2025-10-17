
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, m, k;
vector <int> g[100005], gg[100005];
int ind[100005];
bool ign[100005];

void solve() {
	cin >> n >> m >> k;

	for(int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		ind[v]++;
	}
	
	set <int> st, st2;

	for(int i = 1; i <= n; i++) {
		if(ind[i] == 0) {
			st.insert(i);
			st2.insert(i);
		}
	}

	vector <int> ans;

	int currentIgnore = 0;
	for(int i = 1; i <= n; i++) {
		auto it = prev(st.end());
		int maxi = *it;
		int needToIgnoreForMax = st.size() - 1 - currentIgnore;
		if(ign[maxi]) needToIgnoreForMax++;

		// debug(k);
		// debug(currentIgnore);
		// debug(needToIgnoreForMax);
		// for(auto j : st) {
		// 	cout << j << " ";
		// }
		// cout << "\n";

		if(needToIgnoreForMax <= k) {
			k -= needToIgnoreForMax;
			st.erase(maxi);
			st2.erase(maxi);

			for(auto j : st2) {
				ign[j] = true;
				currentIgnore++;
			}
			st2.clear();

			for(auto j : g[maxi]) {
				ind[j]--;
				if(ind[j] == 0) {
					st.insert(j);
					st2.insert(j);
				}
			}

			if(ign[maxi]) {
				// use this
				gg[ans.back()].pb(maxi);
				ign[maxi] = 0;
				currentIgnore--;
			}
			ans.pb(maxi);
		} else {
			int mini = 0;
			vector <int> er;
			for(auto j : st2) {
				if(k == 0) {
					mini = j;
					break;
				}
				k--;
				ign[j] = true;
				er.pb(j);
				currentIgnore++;
			}

			for(auto j : er) st2.erase(j);

			st.erase(mini);
			st2.erase(mini);

			for(auto j : g[mini]) {
				ind[j]--;
				if(ind[j] == 0) {
					st.insert(j);
					st2.insert(j);
				}
			}

			if(ign[mini]) {
				currentIgnore--;
				ign[mini] = 0;
				gg[ans.back()].pb(mini);
			}
			ans.pb(mini);
		}
	}

	for(auto i : ans)
		cout << i << " ";
	cout << "\n";

	vector <pair<int,int>> edges;
	for(int i = 1; i <= n; i++) {
		for(auto j : gg[i]) {
			edges.pb({i, j});
		}
	}

	cout << edges.size() << "\n";
	for(auto i : edges) {
		cout << i.fi << " " << i.se << "\n";
	}
}

int32_t main() {
	// freopen("graph.in", "r", stdin);
	// freopen("graph.out", "w", stdout);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
