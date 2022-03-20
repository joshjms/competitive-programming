// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, dp[355][355][2], ans;
int c[355][355];

void getc(){
    for(int i = 0; i <= 350; i++){
        for(int j = 0; j <= i; j++){
            if(i == 0 || i == j)
                c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

void solve(){
    cin >> n;
    getc();
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= j; k++){
                // add 
                int add = j - k;
                int rem = n - k;
                if(add == i){
                    dp[i][j][1] += (dp[i - 1][k][0] * c[rem][add]) % mod;
                    dp[i][j][1] += (dp[i - 1][k][1] * c[rem][add]) % mod;
                }
                else{
                    dp[i][j][0] += (dp[i - 1][k][0] * c[rem][add]) % mod;
                    dp[i][j][1] += (dp[i - 1][k][1] * c[rem][add]) % mod;
                }
                dp[i][j][0] %= mod;
                dp[i][j][1] %= mod;
            }
        }
    }
    cout << dp[n][n][1] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}