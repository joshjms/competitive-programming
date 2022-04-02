#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int arr[3][4], akarin;

void solve () {
    akarin = 1e6;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < 4; i++) {
        akarin -= min(arr[0][i], min(arr[1][i], arr[2][i]));
    }
    if(akarin > 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    akarin = 1e6;
    for(int i = 0; i < 4; i++) {
        int res = min(akarin, min(arr[0][i], min(arr[1][i], arr[2][i])));
        akarin -= res;
        cout << res << " ";
    }
    cout << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    for(int ntc = 1; ntc <= tc; ntc++) {
        cout << "Case #" << ntc << ": ";
        solve ();
    }
}