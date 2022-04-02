#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, m, arr[1005][1005], ps[4][1005][1005], maxi[4][1005][1005], ans = -1e9 + 7;

void solve () {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ps[0][i][j] = ps[0][i][j - 1] + arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            ps[1][i][j] = ps[1][i][j + 1] + arr[i][j];
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            ps[2][j][i] = ps[2][j - 1][i] + arr[j][i];
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = n; j >= 1; j--) {
            ps[3][j][i] = ps[3][j + 1][i] + arr[j][i];
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j <= n + 1; j++) {
            for(int k = 0; k <= m + 1; k++) {
                maxi[i][j][k] = -1e18 - 7;
            }
        }
    }

    // for(int i = 0; i < 4; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         for(int k = 1; k <= m; k++) {
    //             cout << ps[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            maxi[1][i][j] = max(ps[1][i][j], maxi[1][i][j - 1]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            maxi[0][i][j] = max(ps[0][i][j], maxi[0][i][j + 1]);
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            maxi[3][j][i] = max(ps[3][j][i], maxi[3][j - 1][i]);
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = n; j >= 1; j--) {
            maxi[2][j][i] = max(ps[2][j][i], maxi[2][j + 1][i]);
        }
    }

    // for(int i = 0; i < 4; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         for(int k = 1; k <= m; k++) {
    //             cout << maxi[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int h = max(maxi[0][i][j] - ps[0][i][j], maxi[1][i][j] - ps[1][i][j]);
            int v = max(maxi[2][i][j] - ps[2][i][j], maxi[3][i][j] - ps[3][i][j]);
            ans = max(ans, h + v + arr[i][j]);
        }
    }
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}