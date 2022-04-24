#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 9;

int cnt[26];
string s, t, a;
int idx;

void solve () {
    cin >> s >> t;
    memset(cnt, 0, sizeof(cnt));
    a = "";
    for(int i = 0; i < t.size(); i++) {
        cnt[t[i] - 'A']++;
    }
    for(int i = s.size() - 1; i >= 0; i--) {
        if(cnt[s[i] - 'A']) {
            cnt[s[i] - 'A']--;
            a += s[i];
        }
    }
    reverse(a.begin(), a.end());
    if(a == t)
        cout << "YES\n";
    else cout << "NO\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while(tc--) solve ();
}