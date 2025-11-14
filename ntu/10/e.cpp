
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, k;
vector <int> g[255];
bool vis[255];
bool temp_vis[255];

void solve() {
	cin >> n >> k;

	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	memset(vis, 0, sizeof(vis));

	set <pair<int,int>> queries;
	
	queue <int> q;
	q.push(1);
	vis[1] = 1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		memset(temp_vis, 0, sizeof(temp_vis));
		queue<vector<int>> q2;
		q2.push({-1,-1,-1,u});
		temp_vis[u] = 1;
		for(int i = 1; i <= k + 1;i++){
			int size = q2.size();

			for(int j = 0; j < size; j++){
				vector<int> front = q2.front(); q2.pop();
				temp_vis[front[3]] = 1;
				
				for(auto a : g[front[3]]){
					if(temp_vis[a]) continue;
					if(front[0] == -1) q2.push({front[3], a, front[3], a});
					else q2.push({front[0], front[1], front[3], a});
				}
			}
		}
		while(!q2.empty()){
			pair<int,int> a = {q2.front()[0], q2.front()[2]}, b = {q2.front()[1], q2.front()[3]};
			if(a.fi > a.se) swap(a.fi, a.se);
			if(b.fi > b.se) swap(b.fi, b.se); 
			vis[q2.front()[3]] = 1; q2.pop();
			queries.insert(a);
			queries.insert(b);
		}
		
		for(int i = 1; i <= n;i++){
			if(!vis[i]) continue;
			memset(temp_vis, 0, sizeof(temp_vis));
			queue<pair<int, int>> q3;
			if(vis[i]) q3.push({i, -1});
			else q3.push({i, i});
			temp_vis[i] = 1;

			for(int j = 1; j <= k;j++){
				int size = q3.size();

				for(int k = 0; k < size; k++){
					pair<int,int> front = q3.front(); q3.pop();
					temp_vis[front.fi] = 1;
					
					for(auto a : g[front.fi]){
						if(temp_vis[a]) continue;
						if(front.se == -1){
							if(vis[a]) q3.push({a, -1});
							else q3.push({a, a});
						} 
						else{
							if(vis[a]) q3.push({a, front.se});
						}
					}
				}
			}

			while(!q3.empty()){
				pair<int,int> front = q3.front(); q3.pop();
				if(front.se != -1) {
					int a = i, b = front.fi;
					if(a > b) swap(a,b);
					queries.insert({a, b});
					vis[front.se] = 1; 
				}
			}
		}
	}
	for(int i = 1; i <= n;i++) {
		if(!vis[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	cout << "? " << queries.size();
	for(auto [a,b] : queries){
		cout << " " << a << " " << b;
	}
	cout << endl;

	map<pair<int,int>, int> mp;
	for(auto [a,b] : queries){
		int c;
		cin >> c;
		mp[{a,b}] = c; 
	}

	vector<int> ans(n + 5, -1);
	while(!q.empty()) q.pop();
	q.push(1);
	ans[1] = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		memset(temp_vis, 0, sizeof(temp_vis));
		queue<pair<int,int>> q2;
		q2.push({u, u});
		temp_vis[u] = 1;
		for(int i = 1; i <= k + 1;i++){
			int size = q2.size();

			for(int j = 0; j < size; j++){
				pair<int,int> front = q2.front(); q2.pop();
				temp_vis[front.se] = 1;
				
				for(auto a : g[front.se]){
					if(temp_vis[a]) continue;
					q2.push({front.fi, a});
				}
			}
		}
		while(!q2.empty()){
			pair<int,int> a = q2.front(); q2.pop();
			if(a.fi > a.se) swap(a.fi, a.se);
			cout << a.fi << " " << a.se << endl;
			cout << ans[a.fi] << " " << mp[{a.fi, a.se}] << endl;
			ans[a.se] = ans[a.fi] ^ mp[{a.fi, a.se}];
		}
		
		for(int i = 1; i <= n;i++){
			if(ans[i] == -1) continue;
			memset(temp_vis, 0, sizeof(temp_vis));
			queue<vector<int>> q3; 
			q3.push({i, -1, ans[i]});
			temp_vis[i] = 1;

			for(int j = 1; j <= k;j++){
				int size = q3.size();

				for(int k = 0; k < size; k++){
					vector<int> front = q3.front(); q3.pop();
					temp_vis[front[0]] = 1;
					
					for(auto a : g[front[0]]){
						if(temp_vis[a]) continue;
						if(front[1] == -1){
							if(vis[a]) q3.push({a, -1, front[2] ^ ans[a]});
							else q3.push({a, a, front[2]});
						} 
						else{
							if(vis[a]) q3.push({a, -1, front[2] ^ ans[a]});
						}
					}
				}
			}

			while(!q3.empty()){
				vector<int> front = q3.front(); q3.pop();
				if(front[1] != -1) {
					ans[front[1]] = front[2];
				}
			}
		}
	}
	cout << "!";
	for(int i = 1; i <= n;i++) cout << " " << ans[i];
	cout << endl;
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
