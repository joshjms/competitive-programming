#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int m, ans;

void solve () {
    m = 0;
    for(int i = 1; i <= 30; i++) {
        cout << "? " << (1ll << (i - 1)) - m << " " << (1ll << (i - 1)) - m + (1ll << i) << "\n";
        cout.flush(); 
        int res; cin >> res;
        if(res == (1ll << i)) m += (1ll << (i - 1));
    }
    cout << "! " << m << "\n";
    cout.flush();
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while(tc--) solve ();
}