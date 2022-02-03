#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, a, b;
int arr[2005];

int sum(int l, int r){
    return arr[r] - arr[l - 1];
}

void solve_1(){
    int banned = 0;
    int ans = 0;
    for(int bit = 40; bit >= 0; bit--){
        // Check if we can erase this bit
        banned |= (1ll << bit);
        int dp[2005];
        fill(dp + 1, dp + n + 1, 1e18 + 7);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if((sum(j, i) & banned) == 0)
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        if(dp[n] > b){
            ans |= (1ll << bit);
            banned ^= (1ll << bit);
        }
    }
    cout << ans << "\n";
}

void solve_2(){
    int banned = 0;
    int ans = 0;
    for(int bit = 40; bit >= 0; bit--){
        banned |= (1ll << bit);
        int dp[105][105];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = 1e18 + 7;
            }
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                // i-th split, j-th sculpture
                for(int k = 1; k <= j; k++){
                    if((sum(k, j) & banned) == 0)
                        dp[j][i] = min(dp[j][i], dp[k - 1][i - 1] + 1);
                }
            }
        }
        bool ok = 0;
        for(int i = a; i <= b; i++)
            ok |= (dp[n][i] <= b ? 1 : 0);
        if(!ok){
            ans |= (1ll << bit);
            banned ^= (1ll << bit);
        }
    }
    cout << ans << "\n";
}

void input(){
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    if(a == 1)
        solve_1();
    else solve_2();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
}