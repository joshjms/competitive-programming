
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, a[200005];
map <int,int> cnt;

void solve() {
	cin >> n;

	cnt.clear();

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	vector <pair<int,int>> v;

	for(auto [k, V] : cnt) {
		v.push_back({V, -k});
	}
	sort(v.begin(), v.end(), greater<pair<int,int>>());

	int score[2];
	score[0] = 0, score[1] = 0;
	int turn = 0; // alice
	for(auto [V, k] : v) {
		// debug(turn);
		// debug(V);
		// debug(-k);

		int forSecond = (-k) / 2;
		int forFirst = (-k) - forSecond;

		score[turn] += forFirst * V;
		score[turn ^ 1] += forSecond * V;

		// debug(score[0]);
		// debug(score[1]);

		(turn -= k) %= 2;
	}

	cout << score[0] << " " << score[1] << "\n";
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
