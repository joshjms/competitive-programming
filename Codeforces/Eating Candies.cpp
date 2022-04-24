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

void solve () {
    cin >> n;
    cout << "Division ";
    if(n >= 1900)
        cout << 1 << "\n";
    else if(n >= 1600)
        cout << 2 << "\n";
    else if(n >= 1400)
        cout << 3 << "\n";
    else cout << 4 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}