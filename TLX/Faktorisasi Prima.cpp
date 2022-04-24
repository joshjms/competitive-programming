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
    for(int i = 2; i <= 1000000; i++) {
        if(n % i == 0) {
            cout << i;
            int t = 0;
            while(n % i == 0) t++, n /= i;
            if(t > 1) cout << "^" << t;
            if(n != 1) cout << " x ";
        }
    }
    cout << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}