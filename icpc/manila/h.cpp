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
	int n,k;
	cin >> n >> k;
	vector<vector<int>> v(n, vector<int> (3));
	for(int i = 0; i < n;i++) {
		cin >> v[i][0];
	}
	for(int i = 0; i < n;i++) {
		cin >> v[i][1];
	}
	for(int i = 0; i < n;i++) {
		v[i][2] = i;
	}

	int target = 0, end = -1;

	sort(v.begin(), v.end());
	vector<int> taken(n, 0);
	for(int i = 0; i < n;i++){
		if(target + v[i][0] <= k) {
			taken[v[i][2]] = 1;
			target += v[i][0];
		}
		else {
			end = i;
			break;
		}
	}

	if(end == -1) end = n;
	priority_queue<pair<int,pair<int,int>>> not_taken_intense;
	priority_queue<pair<int,pair<int,int>>> taken_normal;
	priority_queue<pair<int,pair<int,int>>> taken_upgrade;

	for(int i = 0; i < end;i++) {
		taken_upgrade.push({-(v[i][1] - v[i][0]), {v[i][2], i}});
		taken_normal.push({v[i][0], {v[i][2], i}});
	}
	for(int i = end;i < n;i++){
		not_taken_intense.push({-v[i][1], {v[i][2], i}});
	}

	while(true){
		int left = 1e18, right = 1e18;

		while(!taken_normal.empty() && taken[taken_normal.top().second.fi] != 1) taken_normal.pop();
		while(!taken_upgrade.empty() && taken[taken_upgrade.top().second.fi] != 1) taken_upgrade.pop();
		while(!not_taken_intense.empty() && taken[not_taken_intense.top().second.fi] != 0) not_taken_intense.pop();

		if(!not_taken_intense.empty() && !taken_normal.empty()) {
			left = -not_taken_intense.top().first - taken_normal.top().first;
		}
		if(!taken_upgrade.empty()) right = -taken_upgrade.top().first;
		
		//cout << left << " " << right << " " << target << endl;
		if(min(left, right) + target > k) break;

		if(left < right){
			int idx1 = not_taken_intense.top().second.fi, idx2 = taken_normal.top().second.fi; 
			int v_idx = taken_normal.top().se.se;
			not_taken_intense.pop(); taken_normal.pop();
			taken[idx1] = 2;
			taken[idx2] = 0;
			not_taken_intense.push({-(v[v_idx][1]), {idx2, v_idx}});
			target += left;
		}
		else{
			int idx1 = taken_upgrade.top().second.fi; taken_upgrade.pop();
			taken[idx1] = 2;
			target += right;
		}
	}
	for(auto a : taken) cout << a;
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
