
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 676767677;

int n, a[100005];

void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]--;
	}

	int ans = 0;

	int P = a[n];

	int b[n + 1];
	memset(b, 0, sizeof(b));
	for(int i = 1; i <= n; i++)
		b[i] = a[i] - n + i + P;

	int p[n + 1];
	memset(p, 0, sizeof(p));
	for(int i = 1; i <= n; i++) {
		p[i] = b[i] - p[i - 1];
	}

	bool can = true;
	for(int i = 1; i <= n; i++) {
		if(!(p[i] - p[i - 1] >= 0 && p[i] - p[i - 1] <= 1)) {
			can = false;
			break;
		}
	}
	if(p[n] != P) can = false;

	if(can) ans++;

	P = a[n] + 1;
	memset(b, 0, sizeof(b));
	memset(p, 0, sizeof(p));

	for(int i = 1; i <= n; i++)
		b[i] = a[i] - n + i + P;

	for(int i = 1; i <= n; i++) {
		p[i] = b[i] - p[i - 1];
	}

	can = true;
	for(int i = 1; i <= n; i++) {
		if(!(p[i] - p[i - 1] >= 0 && p[i] - p[i - 1] <= 1)) {
			can = false;
			break;
		}
	}
	if(p[n] != P) can = false;

	if(can) ans++;
 

	cout << ans << "\n";
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
