#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

bool cnt[15];
string s;

void solve () {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i] - '0'] = 1;
    }
    for(int i = 0; i <= 9; i++)
        if(!cnt[i]) {
            cout << i << "\n";
            return;
        }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}