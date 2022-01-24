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

int n, arr[55], p, sum;
ld c[55][55], dp[55][55][55][55];
ld ans;

void solve(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> p;
    if(sum <= p){
        cout << n << "\n";
        return;
    }
    for(int i = 1; i <= n; i++)
        dp[i][0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l <= p; l++){
                    dp[i][j + 1][k][l] += dp[i][j][k][l];
                    if(j + 1 != i) if(arr[j + 1] + l <= p){
                        dp[i][j + 1][k + 1][l + arr[j + 1]] += dp[i][j][k][l];
                    }
                }
            }
        }
        for(int k = 0; k < n; k++){
            for(int l = p - arr[i] + 1; l <= p; l++){
                ans += dp[i][n][k][l] * k / c[n - 1][k] / n;
            }
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}