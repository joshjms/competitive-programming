#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, x, y, a[20], b[20];
int dp[300005];

void solve(){
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 1; i < (1ll << n); i++)
        dp[i] = 1e18 + 7;
    for(int i = 0; i < (1ll << n); i++){
        for(int j = 0; j < n; j++) if((i & (1ll << j)) == 0){
            // bring A[j] forward
            int prefix = 0;

            for(int k = 0; k < n; k++)
                if((i & (1ll << k)) > 0)
                    prefix++;

            int cost = dp[i];
            int shift = 0;

            for(int k = j + 1; k < n; k++)
                if((i & (1ll << k)) > 0)
                    shift++;

            cost += (j + shift - prefix) * y + abs(a[j] - b[prefix]) * x;
            dp[(i | (1ll << j))] = min(dp[(i | (1ll << j))], cost);
        }
    }
    // for(int i = 0; i < (1ll << n); i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    cout << dp[(1ll << n) - 1] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}