
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int javaHashCode(const string &s) {
    long long h = 0; 
    for (char c : s) {
        h = 31 * h + static_cast<unsigned char>(c); 
        h = (int)h; 
    }
    return (int)h;
}

void solve() {
	int n;
	cin >> n;

	string s = "dP", t = "co";
	vector <string> ans;
	
	for(int i = 0; i < n; i++) {
		int tmp = i;
		string x = "";
		
		for(int j = 0; j < 10; j++) {
			if(i & (1 << j)) {
				x += s;
			} else {
				x += t;
			}
		}
		cout << x << "\n";
	}
}

int32_t main() {
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
