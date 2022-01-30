#include "challenge.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

ll n, arr[1005];
ll dp[1005][5005], dp2[1005][5005];

ll queries;

void initialize(int N, vector <int> A) {
    n = N;
    for(int i = 1; i <= n; i++)
        arr[i] = A[i - 1];
    sort(arr + 1, arr + n + 1, greater<int>());
    arr[0] = 1e9 + 7;
    memset(dp2, 0, sizeof(dp2));
    for(int i = 5000; i >= 0; i--){
        dp[n][i] = (i >= arr[n] ? -1 : i % arr[n]);
        dp2[n][i] = (i >= arr[n] ? 0 : 1);
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 5000; j++){
            dp[i][j] = max(dp[i + 1][j % arr[i + 1]], dp[i + 1][j]);
            ll val = j;
            if(dp[i + 1][val % arr[i + 1]] == dp[i][val]){
                (dp2[i][j] += dp2[i + 1][val % arr[i + 1]]) %= mod;
            }
            if(dp[i + 1][val] == dp[i][val]){
                (dp2[i][j] += dp2[i + 1][val] * (n - i - 1) % mod) %= mod;
            }
        }
    }
    return;
}

int solve_challenge(int x, int t) {
    ll maxi = 0;
    for(int i = 1; i <= n; i++){
        maxi = max(maxi, dp[i][x % arr[i]]);
    }
    if(t == 0){
        return maxi;
    }
    else{
        ll mult = 1;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            // start at arr[i]
            if(dp[i][x % arr[i]] < maxi){
                (mult *= n - i) %= mod;
                continue;
            }
            (ans += (dp2[i][x % arr[i]] * mult) % mod) %= mod;
            (mult *= n - i) %= mod;
        }
        return ans % mod;
    }
}