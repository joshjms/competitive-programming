#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int t, idx;
int p[1000005];
bool red[1000005];

void sieve() {
    for(int i = 2; i <= 1000000; i++) {
        if(red[i] == false) {
            p[++idx] = i;
            for(int j = i * i; j <= 1000000; j += i) {
                red[j] = true;
            }
        }
    }
}

void solve () {
    sieve();
    cin >> t;
    for(int k; t--;) {
        cin >> k;
        cout << p[k] << "\n";
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}