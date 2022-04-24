#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 998244353;

int n, m, ans;
string s;
int dp[300005];
string a[300005];

void dfs(int pos) {
    if(pos * 2 + 1 < m){
        dfs(pos * 2);
        dfs(pos * 2 + 1);

        bool ok = true;

        for(int i = 0; i < 20; i++) {
            // cout << a[pos * 2][i] << " " << a[pos * 2 + 1][i] << "\n";
            if(a[pos * 2][i] != a[pos * 2 + 1][i])
                ok = false;
        }

        if(ok) {
            //debug("same");
            dp[pos] = ((dp[pos * 2] * dp[pos * 2 + 1])) % mod;
        }
        else dp[pos] = (dp[pos * 2] * dp[pos * 2 + 1] * 2) % mod;

        for(int i = 1; i <= 20; i++) {
            a[pos][i] = a[pos * 2][i - 1] + a[pos * 2 + 1][i - 1];
        }

        if(s[pos] == 'A') {
            a[pos][0] = 1;
        }
        return;
    }
    else {
        if(s[pos] == 'A') {
            a[pos][0] = 1;
        }
        dp[pos] = 1;
        return;
    }
}

void solve () {
    cin >> n >> s;
    s = 'x' + s;
    m = (1ll << n);
    dfs(1);
    for(int i = 1; i < m; i++)
        cout << dp[i] << " ";
    cout << "\n";
    cout << dp[1] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}