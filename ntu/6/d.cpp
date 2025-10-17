
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int _2[65], _3[65], m2, m3;
unordered_map<int,pair<int,int>> mp;
unordered_map<int,pair<pair<int,int>,pair<int,int>>> mpp;

vector <int> ans;
bool flag = 0;

void dfs(int cur, int th, int tw) {
	if(flag) return;

	if(cur == 0) {
		cout << ans.size() << "\n";
		for(auto i : ans)
			cout << i << " ";
		cout << "\n";

		flag = 1;
		return;
	}
	if(th < 0 || tw > m2) return;

	dfs(cur, th - 1, tw);
	if(flag) return;

	dfs(cur, th, tw + 1);
	if(flag) return;

	if(_3[th] <= floor(cur / _2[tw])) {
		ans.push_back(_2[tw] * _3[th]);
		dfs(cur - _2[tw] * _3[th], th - 1, tw + 1);
		ans.pop_back();
	}
	if(flag) return;
}

void solve() {
	int X;
	cin >> X;
	
	ans.clear();
	flag = 0;

	if(mp.count(X)) {
		cout << 1 << "\n";
		cout << X << "\n";
		return;
	}
	
	dfs(X, m3, 0);
}

int32_t main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	_2[0] = 1;
	for(int i = 1; i < 60; i++) {
		if(_2[i - 1] * 2 > 1e18) break;
		_2[i] = (_2[i - 1] * 2);
		m2 = i;
	}

	_3[0] = 1;
	for(int i = 1; i < 60; i++) {
		if(_3[i - 1] * 3 > 1e18) break;
		_3[i] = (_3[i - 1] * 3);
		m3 = i;
	}

	// for(int i = 0; i <= m2; i++) {
	// 	for(int j = 0; j <= m3; j++) {
	// 		if(_2[i] <= floor(1e18 / _3[j])) {
	// 			int mul = _2[i] * _3[j];
	// 			mp[mul] = {i, j};
	// 		}
	// 	}
	// }

	// for(int i = 0; i <= m2; i++) {
	// 	for(int j = 0; j <= m3; j++) {
	// 		if(_2[i] > floor(1e18 / _3[j])) continue;
			
	// 		for(int ii = 0; ii <= m2; ii++) {
	// 			for(int jj = 0; jj <= m3; jj++) {
	// 				if(_2[ii] > floor(1e18 / _3[jj])) continue;
	// 				if((ii <= i && jj <= j) || (i <= ii && j <= jj)) continue;
	// 				int c1 = _2[i] * _3[j];
	// 				int c2 = _2[ii] * _3[jj];
					
	// 				if(c1 + c2 <= 1e18) {
	// 					mpp[c1 + c2] = {{i, j}, {ii, jj}};
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
