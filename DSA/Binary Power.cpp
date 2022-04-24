#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int a, b;

int modex(int a, int b) {
    // find a ^ b
    int res = 1;
    int x = a;
    for(int i = 0; i < 30; i++) {
        if(b & (1ll << i)) {
            // if the bit is on
            (res *= x) %= 5;
        }
        (x *= x) %= 5;
    }
    return res;
}

void solve () {
    cin >> a >> b;
    cout << modex(a, b) << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}