
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n;
string s;

void solve() {
	cin >> n >> s;
	
	int a[n + 5];
	memset(a, 0, sizeof(a));

	for(int i = 0; i < n; i++) a[i + 1] = s[i] - '0';
	a[0] = 1;
	a[n + 1] = 1;

	int dir[n + 5];
	memset(dir, -1, sizeof(dir));

	// 0 = left, 1 = right

	for(int i = 1; i <= n; i++) {
		if(a[i]) {
			if(a[i + 1] && !a[i - 1]) {
				if(dir[i - 1] != -1 && dir[i - 1] != 0) {
					cout << "NO" << "\n";
					return;
				}
				//cout << "set " << i - 1 << " left\n"; 
				dir[i - 1] = 0;
			}
			if(a[i - 1] && !a[i + 1]) {
				if(dir[i + 1] != -1 && dir[i + 1] != 1) {
					cout << "NO" << "\n";
					return;
				}

				//cout << "set " << i + 1 << " right\n"; 
				dir[i + 1] = 1;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		if(a[i]) {
			if(i > 1 && !a[i - 1] && i < n && !a[i + 1]) {
				// solo flower
				int leftDir = dir[i - 1];
				int rightDir = dir[i + 1];

				if(leftDir != -1 && rightDir != -1 && leftDir == rightDir) {
					cout << "NO" << "\n";
					return;
				}

				if(leftDir != -1) {
					dir[i + 1] = leftDir ^ 1;
				}

				if(rightDir != -1) {
					dir[i - 1] = rightDir ^ 1;
				}
			}
		}
	}

	// for(int i = 1; i <= n; i++)
	// 	cout << dir[i] << " ";
	// cout << "\n";

	cout << "YES\n";
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
