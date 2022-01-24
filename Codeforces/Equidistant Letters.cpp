#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

string s;

void solve(){
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}