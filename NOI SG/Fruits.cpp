#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define debug(x) cout << #x << " => " << x << "\n"

#define fi first
#define se second

const int mod = 1e9 + 7;

int n, a[400005], c[400005], pos[400005];
int dp[2005][2005], ans[2005];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i]!=-1) pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = -1e18 - 7;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(pos[j] != 0 && pos[j] != i) continue;
            if(a[i] != -1 && a[i] != j) continue;
            for(int k = (i == 1 ? 0 : 1); k <= n; k++){
                if (k < j) dp[i][j] = max(dp[i][j], dp[i - 1][k] + c[j]);
                else dp[i][k] = max(dp[i][k], dp[i - 1][k]);
            }
            ans[i] = max(ans[i], dp[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans[i] = max(ans[i], dp[i][j]);
            // if(dp[i][j] < -1e17)
            //     cout << "- ";
            // else cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}