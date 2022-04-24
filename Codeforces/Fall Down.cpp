#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, m;
char c[55][55];

void drop(int x, int y) {
    if(x == n || c[x + 1][y] != '.') return;
    swap(c[x][y], c[x + 1][y]);
    drop(x + 1, y);
}

void solve () {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= m; j++) {
            if(c[i][j] == '*')
                drop(i, j);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << c[i][j];
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}