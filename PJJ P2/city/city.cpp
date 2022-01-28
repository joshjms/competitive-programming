#include "city.h"

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

int n, m, s, t;
vector <pair<int,ll>> g[100005];
priority_queue <int> pq;

struct disjoint_set_union{
    int par[100005];
    void find(int u){
        return (u == par[u] ? u : par[u] = find(par[u]));
    }
    void joint(int u, int v){
        
    }
}

pair<int, int> getBestXY(int N, int M, int S, int T, vector<int> A,  vector<int> B,  vector<int> C) {
    n = N, m = M, s = S, t = T;
    for(int i = 0; i < n; i++){
        g[A[i]].pb({B[i], C[i]});
        g[B[i]].pb({A[i], C[i]});
    }

}  