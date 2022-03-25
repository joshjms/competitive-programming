#include "souvenir.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"

ll n, m, a[2005], b[2005], x[2005], y[2005], pos_a[5005], pos_b[5005];
ll ans;

ll tree[4 * 2005];

void upd(ll idx, ll l, ll r, ll x, ll v){
    if(l == r){
        tree[idx] = v;
        return;
    }
    ll mid = (l + r) / 2;
    if(x <= mid) upd(idx * 2, l, mid, x, v);
    else upd(idx * 2 + 1, mid + 1, r, x, v);
    tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

ll query(ll idx, ll l, ll r, ll x, ll y){
    if(l > r || l > y || r < x) return 0;
    if(l >= x && r <= y) return tree[idx];
    ll mid = (l + r) / 2;
    return max(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

ll par[2005], val[2005];

void init(){
    for(ll i = 1; i <= m; i++){
        par[i] = i;
        val[i] = 0;
    }
}

ll find(ll u){
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}

ll join(ll u, ll v){
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    par[u] = v;
    val[v] += val[u];
    return 1;
}

ll buy_souvenir(vector<int> A, vector<int> X, vector<int> B, vector<int> Y) {
    n = A.size();
    m = B.size();
    for(ll i = 1; i <= n; i++)
        a[i] = A[i - 1], x[i] = X[i - 1];
    for(ll i = 1; i <= m; i++){
        b[i] = B[i - 1], y[i] = Y[i - 1];
        ans += y[i];
    }
    for(ll i = 1; i <= n; i++)
        pos_a[a[i]] = i;
    for(ll i = 1; i <= m; i++)
        pos_b[b[i]] = i;
    for(ll i = 1; i <= n; i++){
        init();
        bool unlocked[m + 1];
        memset(unlocked, 0, sizeof(unlocked));
        for(ll j = 1; j <= m; j++){
            if(pos_a[b[j]] < i){
                unlocked[j] = true;
                val[j] = y[j];
            }
            else val[j] = 0;
        }
        for(ll j = 2; j <= m; j++){
            if(unlocked[j] && unlocked[j - 1]){
                join(j - 1, j);
            }
        }
        for(ll j = 1; j <= m; j++){
            upd(1, 1, m, j, val[find(j)]);
        }
        ll sum = 0;
        for(ll j = i; j <= n; j++)
            sum += x[j];
        for(ll j = n; j >= i; j--){
            ans = max(ans, query(1, 1, m, 1, m) + sum);
            if(j == i) continue;
            if(pos_b[a[j]]){
                ll p = pos_b[a[j]];
                unlocked[p] = true;
                val[p] = y[p];
                if(p < m && unlocked[p + 1])
                    join(p, p + 1);
                if(p > 1 && unlocked[p - 1])
                    join(p, p - 1);
                upd(1, 1, m, p, val[find(p)]);
            }
            sum -= x[j];
        }
    }
    return ans;
}

// int main() {
//   int N, M;
//   scanf("%d %d", &N, &M);
//   std::vector<int> A(N), X(N), B(M), Y(M);
//   for (int i = 0; i < N; i++) {
//     scanf("%d", &A[i]);
//   }
//   for (int i = 0; i < N; i++) {
//     scanf("%d", &X[i]);
//   }
//   for (int i = 0; i < M; i++) {
//     scanf("%d", &B[i]);
//   }
//   for (int i = 0; i < M; i++) {
//     scanf("%d", &Y[i]);
//   }
//   printf("%lld\n", buy_souvenir(A, X, B, Y));
//   return 0;
// }
