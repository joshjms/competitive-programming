#include "walk.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"

ll n, m, k, ans;
vector <int> g[45];
ll dp[15][1000005];
queue <pair<ll, ll>> q;
ll cnt[1000005];

ll find_best_walk(int N, long long K, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    n = N;
    k = K;
    m = U.size();
    for(int i = 0; i < m; i++){
        g[U[i]].pb(V[i]);
    }
    for(int i = 0; i < n; i++)
        dp[i][0] = 1;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            for(auto c : g[j]){
                dp[c][i + 1] += dp[j][i];
            }
        }
    }
    for(int i = 1; i <= k; i++)
        for(int j = 0; j < n; j++)
            cnt[i] += dp[j][i];
    for(int i = 1; i <= k; i++){
        if(i > 1) cnt[i] += cnt[i - 1];
        // cout << cnt[i] << " ";
        if(cnt[i] >= k) return i;
    }
    // cout << "\n";
    return -1;
}

// int main() {
//   int N, M;
//   long long K;
//   scanf("%d %d %lld", &N, &M, &K);
//   std::vector<int> U(M), V(M), W(M);
//   for (int i = 0; i < M; i++) {
//     scanf("%d %d %d", &U[i], &V[i], &W[i]);
//   }
//   printf("%lld\n", find_best_walk(N, K, U, V, W));
//   return 0;
// }
