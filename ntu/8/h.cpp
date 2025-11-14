
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
	// code here
	int n;
	int s;	
	cin >> n >> s;
	unordered_map<string, int> name_pos;
	unordered_map<int, string> pos_name;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		name_pos[name] = i;
		pos_name[i] = name;
	}
	while (s--) {
		string t, name;
		cin >> t >> name;
		if (t == "insert") {
			int pos;
			cin >> pos;
			for (int i = n - 1; i >= pos; i--) {
				string now = pos_name[i];
				name_pos[now]++;
				pos_name[i + 1] = now;
			}
			name_pos[name] = pos;
			pos_name[pos] = name;
			n++;
		}
		else if (t == "depart") {
			int idx = name_pos[name];
			for (int i = idx + 1; i < n; i++) {
				string now = pos_name[i];
				name_pos[now]--;
				pos_name[i - 1] = now;
			}
			n--;
		}
		else {
			int dis;
			cin >> dis;
			int pos = name_pos[name];
			if (dis == 0) continue;
			else if (dis < 0) {
				for (int i = 1; i <= abs(dis); i++) {
					string now = pos_name[pos - i];
					name_pos[now]++;
					pos_name[pos - i + 1] = now;
				}
				name_pos[name] = pos + dis;
				pos_name[pos + dis] = name;
			}
			else {
				for (int i = 1; i <= abs(dis); i++) {
					string now = pos_name[pos + i];
					name_pos[now]--;
					pos_name[pos + i - 1] = now;
				}
				name_pos[name] = pos + dis;
				pos_name[pos + dis] = name;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << pos_name[i] << " ";
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
