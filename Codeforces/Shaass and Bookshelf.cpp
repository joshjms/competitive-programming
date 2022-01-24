#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int n, t[105], w[105], a, b;
vector <int> v[2];

int thick, width, ans = 1e18 + 7;

signed main(){
	cin >> n;
	for(int i = 0; i < 2; i++)
		v[i].push_back(0);
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> w[i];
		v[t[i] - 1].push_back(w[i]);
	}
	for(int i = 0; i < 2; i++)
		sort(v[i].begin(), v[i].end());
	for(int i = 0; i < 2; i++){
		for(int j = 1; j < v[i].size(); j++)
			v[i][j] += v[i][j - 1];
	}
	a = v[0].size() - 1;
	b = v[1].size() - 1;
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			thick = i + j * 2;
			width = v[0][a - i] + v[1][b - j];
			if(width <= thick){
				ans = min(ans, thick);
			}
		}
	}
	cout << ans << "\n";
}