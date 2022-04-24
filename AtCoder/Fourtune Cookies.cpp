#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int a, b, c, d, s;

void solve () {
    cin >> a >> b >> c >> d;
    s = a + b + c + d;
    if(s % 2) {
        cout << "No\n";
        return;
    }
    s /= 2;
    if(a == s || b == s || c == s || d == s || a + b == s || a + c == s || a + d == s || b + c == s || b + d == s || c + d == s)
        cout << "Yes\n";
    else cout << "No\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}