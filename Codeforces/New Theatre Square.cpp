// AKARINNN!!!!!!!!! <3

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m, x, y, akari;
char arr[105][1005];
int dp[105][1005];

void solve(){
    cin >> n >> m >> x >> y;
    akari = 0;
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= n + 1; j++){
            arr[i][j] = '*';
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == '*')
                dp[i][j] = dp[i][j - 1];
            else{
                dp[i][j] = dp[i][j - 1] + x;
                if(arr[i][j - 1] == '.')
                    dp[i][j] = min(dp[i][j], dp[i][j - 2] + y);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        akari += dp[i][m];
    cout << akari << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}