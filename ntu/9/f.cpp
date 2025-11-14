
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
	string s;
	cin >> s;
	s[0] = '9';

	bool neg = false;
	string tmp = "";
	vector <pair<string, int>> v[2];
	int ord = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '-') {
			v[neg].pb({tmp, ++ord});
			neg = true;
			tmp = "";
		} else if(s[i] == '+') {
			v[neg].pb({tmp, ++ord});
			neg = false;
			tmp = "";
		} else {
			tmp += s[i];
		}
	}

	if(tmp != "") {
		v[neg].pb({tmp, ++ord});
	}

	for(int i = 0; i < v[0].size(); i++) {
		for(int j = 0; j < v[0][i].fi.size(); j += 2) {
			if(j == 0 || v[0][i].fi[j - 1] == '*')
				v[0][i].fi[j] = '9';
			else v[0][i].fi[j] = '1';
		}
	}

	int mini = 0;

	int num = 1, den = 1;
	vector <int> cnt[20005], nCnt[20005];

	int real[20005];
	int moved[20005];
	int ceil[20005];
	memset(real, 0, sizeof(real));
	memset(moved, 0, sizeof(moved));
	memset(ceil, 0, sizeof(ceil));
	
	vector <pair<int,int>> anneFrank;

	for(int i = 0; i < v[1].size(); i++) {
		int tmp = 0;
		for(int j = 0; j < v[1][i].fi.size(); j += 2) {
			if(j == 0 || v[1][i].fi[j - 1] == '*')
				v[1][i].fi[j] = '1';
			else tmp++;
		}

		if(tmp) {
			cnt[tmp].pb(i);
			real[tmp]++;
			anneFrank.pb({tmp, i});
		}
	}
	sort(anneFrank.begin(), anneFrank.end());

	for(int i = 10000; i > 0; i--) {
		moved[i] += real[i];
		moved[i - 1] += moved[i] / 9;
		moved[i] %= 9;
	}
	for(int i = 10000; i >= 0; i--) {
		ceil[i] = moved[i];
		if(ceil[i + 1]) ceil[i]++;
	}
	
	// for(int i = 0; i <= 10; i++)
	// 	cout << moved[i] << " ";
	// cout << "\n";
	
	// for(int i = 0; i <= 10; i++)
	// 	cout << ceil[i] << " ";
	// cout << "\n";

	vector <int> georgeFloyd;
	int idx = 0;
	for(int i = 0; i < 20000; i++) {
		for(int j = 0; j < moved[i]; j++) {
			int cur[16];
			memset(cur, 0, sizeof(cur));

			while(cur[0] == 0) {
				int y = anneFrank[idx].fi;
				int x = anneFrank[idx].se;
				idx++;
				cur[y - i]++;
				
				int ii = 0;
				for(int k = 0; k < v[1][x].fi.size(); k++) {
					if(v[1][x].fi[k - 1] == '/') {
						if(ii < georgeFloyd.size()) {
							v[1][x].fi[k] = char(georgeFloyd[ii] + '0');
							ii++;
						} else {
							v[1][x].fi[k] = '9';
						}
					}
				}

				for(int k = 15; k > 0; k--) {
					cur[k - 1] += cur[k] / 9;
					cur[k] %= 9;
				}

			}
		}

		georgeFloyd.pb(ceil[i + 1]);
		if(georgeFloyd.back() == 0) break;
	}

	string ans = "";

	int idxPos = 0, idxNeg = 0;
	while(idxPos < v[0].size() || idxNeg < v[1].size()) {
		if(idxPos >= v[0].size()) {
			ans += "-";
			ans += v[1][idxNeg].fi;
			idxNeg++;
			continue;
		}
		if(idxNeg >= v[1].size()) {
			ans += "+";
			ans += v[0][idxPos].fi;
			idxPos++;
			continue;
		}
		if(v[0][idxPos].se < v[1][idxNeg].se) {
			ans += "+";
			ans += v[0][idxPos].fi;
			idxPos++;
			continue;
		} else {
			ans += "-";
			ans += v[1][idxNeg].fi;
			idxNeg++;
			continue;
		}
	}

	for(int i = 1; i < ans.size(); i++)
		cout << ans[i];


	// for (int i = 1; i < s.size(); i+= 2) {
	// 	if (s[i] == '-') {
	// 		neg = true;
	// 		s[i + 1] = '1';
	// 	}
	// 	else if (s[i] == '+') {
	// 		neg = false;
	// 		s[i + 1] = '9';
	// 	}
	// 	else if (s[i] == '*') {
	// 		if (neg) s[i + 1] = '1';
	// 		else s[i + 1] = '9';
	// 	}
	// 	else s[i + 1] = '1';
	// }
	// cout << s;
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
