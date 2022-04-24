#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, a[100005], g;

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        g = __gcd(a[i], g);
    }
    cout << g << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}