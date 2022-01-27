#include "art.h"

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

int n, arr[5005], dp[5005][5005][2];
vector <int> ans;

vector <int> calculate_steps(int N, vector<int> A) {
	n = N;
	for(int i = 1; i <= n; i++)
		arr[i] = A[i - 1];
    for(int i = 0; i <= n + 2; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = 1e9 + 7;
            }
        }
    }
    dp[1][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            // take
            dp[i + 2][j + 1][1] = min(dp[i + 2][j + 1][1], dp[i][j][0] + max(0, arr[i - 1] - arr[i] + 1) + max(0, arr[i + 1] - arr[i] + 1));
            dp[i + 2][j + 1][1] = min(dp[i + 2][j + 1][1], dp[i][j][1] + max(0, min(arr[i - 1], arr[i - 2] - 1) - arr[i] + 1) + max(0, arr[i + 1] - arr[i] + 1));
            // not take
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0]);
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1]);
        }
    }
    for(int i = 1; i <= (n + 1) / 2; i++){
        ans.pb(min(dp[n + 1][i][0], min(dp[n + 1][i][1], min(dp[n + 2][i][0], dp[n + 2][i][1]))));
    }
	return ans;
}
