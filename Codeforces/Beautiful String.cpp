#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

string s;

void check(int idx, char c) {
    if((idx > 0 && s[idx - 1] == c) || (idx < s.size() - 1 && s[idx + 1] == c))
        return;
    s[idx] = c;
}

void solve () {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '?'){
            check(i, 'a');
            check(i, 'b');
            check(i, 'c');
        }
    }
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == s[i + 1]){
            cout << -1 << "\n";
            return;
        }
    }
    cout << s << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}