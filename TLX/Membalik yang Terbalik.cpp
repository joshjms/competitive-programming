#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int a, b, c;

int reverse(int x) {
    int res = 0;
    while(x) {res = res * 10 + x % 10; x /= 10; }
    return res;
}

void solve () {
    cin >> a >> b;
    cout << reverse(reverse(a) + reverse(b)) << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}