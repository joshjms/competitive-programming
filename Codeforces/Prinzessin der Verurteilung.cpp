#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n;
string s, t;

string nextString(string x) {
    string ret;
	x[x.size() - 1]++;
	for(int i = x.size() - 1; i > 0; i--){
		if(x[i] - 'a' < 26) continue;
		x[i - 1] += (x[i] - 'a' + 1) / 26;
		x[i] = char((x[i] - 'a') % 26 + 'a');
	}
	if(x[0] - 'a' >= 26){
		for(int i = 1; i <= x.size() + 1; i++)
			ret += 'a';
		return ret;
	}
	else return x;
}

void solve () {
    cin >> n >> s;
    t = "a";
    for(int i = 1; true; i++) {
        if(s.find(t) == -1) {
            cout << t << "\n";
            break;
        }
        t = nextString(t);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}