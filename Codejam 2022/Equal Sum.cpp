#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int ntc;

int n, arr[1005], sa, sb, sc;
vector <int> ans, a, b;

void solve () {
    cin >> n;

    for(int m = 1; m <= 1e9; m *= 10) {
        for(int j = 0; j * m <= 1e9 && j <= 9; j++) {
            if(a.size() < n && j * m > 0 && j * m <= 1e9) a.pb(j * m);
        }
    }
    
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    
    b.resize(n);

    for(int i = 0; i < n; i++)
        cin >> b[i];

    sort(b.begin(), b.end());
    
    for(int i : a)
        sa += i;
    for(int i : b)
        sb += i;
    sc = sa + sb;

    assert(sc % 2 == 0);

    sc /= 2;

    int u = b.size() - 1;

    while(sc > sa) {
        sc -= b[u];
        ans.pb(b[u]);
        u--;
    }

    int akari = 1;

    while(sc) {
        ans.pb(akari * (sc % 10));
        akari *= 10;
        sc /= 10;
    }

    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC; cin >> TC;
    for(ntc = 1; ntc <= TC; ntc ++) {
        solve (); 
    }
}